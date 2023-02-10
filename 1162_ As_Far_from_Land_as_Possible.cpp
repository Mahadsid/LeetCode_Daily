// Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.
// The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

// Example 1:
// Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
// Output: 2
// Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.
// Approach for this Problem:
// Initialize a queue and add all the land cells to the queue.
// If the queue is empty or contains all the cells in the grid, return -1. This means there are no water cells or all cells are land cells.
// Perform a BFS from the land cells and update the distance of each water cell to the nearest land cell.
// The final answer is the maximum distance among all the water cells, which is the number of iterations in the BFS.
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        //Note: The copy matrix visited can be avoided by updating the original matrix grid but changing the input parameter is not considered under good practices. That's why we are taking extra 2d matrix visited
        vector<vector<int>> visited = grid;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 1) 
                    q.push({i, j});
            }
        }
        if (q.empty() || q.size() == n * n) 
            return -1;
        int distance = -1;
        // visit all four direction i.e. right, left, up, down
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front();
                q.pop();
                for (auto [dx, dy] : dirs) {
                    int i = x + dx, j = y + dy;
                    if (i >= 0 && i < n && j >= 0 && j < n && visited[i][j] == 0) {
                        visited[i][j] = 1;
                        q.push({i, j});
                    }
                }
            }
            distance++;
        }
        return distance;
    }
};
