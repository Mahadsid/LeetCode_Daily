// You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.

// You start on square 1 of the board. In each move, starting from square curr, do the following:

// Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
// This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
// If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
// The game ends when you reach the square n2.
// A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n2 do not have a snake or ladder.

// Note that you only take a snake or ladder at most once per move. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.

// For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.
// Return the least number of moves required to reach the square n2. If it is not possible to reach the square, return -1.

 

// Example 1:


// Input: board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
// Output: 4
// Explanation: 
// In the beginning, you start at square 1 (at row 5, column 0).
// You decide to move to square 2 and must take the ladder to square 15.
// You then decide to move to square 17 and must take the snake to square 13.
// You then decide to move to square 14 and must take the ladder to square 35.
// You then decide to move to square 36, ending the game.
// This is the lowest possible number of moves to reach the last square, so return 4.
// Intuition
// The problem is asking us to find the minimum number of moves required to reach the end of a board game represented by a 2D grid (snakes and ladders game). The key observation here is that the board can be represented by a 1D array, where each element in the array corresponds to a cell in the 2D grid. This allows us to use a breadth-first search (BFS) algorithm to traverse the board and find the shortest path to the end.

// The BFS algorithm works by starting from the first cell (0th index in the 1D array) and exploring all its neighboring cells that can be reached in one move (in this case, the next 6 cells in the 1D array). For each of these neighboring cells, we check if it has a snake or ladder and update the next cell accordingly. We also keep track of the distance (number of moves) to each cell and use this information to determine the minimum number of moves required to reach the end.

// The algorithm continues this process until the end cell (last index in the 1D array) is reached, at which point the algorithm returns the minimum number of moves required to reach the end. If the end is not reached, the algorithm returns -1 indicating that it is impossible to reach the end.

// Approach
// The approach used in this solution is Breadth First Search (BFS). It first flattens the board into a 1D array and then uses a queue to keep track of the current position and the distance from the start. The algorithm starts at the first position (0) and uses a loop to check all possible moves (1-6) from the current position. If the next position has not been visited yet, it updates the distance and pushes it into the queue. If the next position is a snake or ladder, it updates the position to the end of the snake or ladder. The algorithm continues this process until it reaches the end of the board or the queue is empty. If the end of the board is reached, it returns the distance, otherwise, it returns -1.

// Complexity
// Time complexity:
// O(n2)O(n^2)O(n 
// 2
//  ) :
// where n is the size of the board. This is because the algorithm must visit each cell in the board at most once, and the number of cells in the board is n^2.

// Space complexity:
// O(n2)O(n^2)O(n 
// 2
//  ) :
// we use an array of size n^2 to store the flattened board and another array of size n^2 to store the distance from each cell to the starting cell. Additionally, we use a queue to keep track of the cells to be visited, which also takes up O(n^2) space in the worst case scenario.

// Code
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
            int n = board.size();
    vector<int> flattenedBoard(n * n);
    int index = 0;
    bool leftToRight = true;
    for (int i = n - 1; i >= 0; i--) {
        if (leftToRight) {
            for (int j = 0; j < n; j++) {
                flattenedBoard[index++] = board[i][j];
            }
        } else {
            for (int j = n - 1; j >= 0; j--) {
                flattenedBoard[index++] = board[i][j];
            }
        }
        leftToRight = !leftToRight;
    }
    vector<int> dist(n * n, -1);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr == n * n - 1) {
            return dist[curr];
        }
        for (int i = 1; i <= 6; i++) {
            int next = curr + i;
            if (next >= n * n) {
                continue;
            }
            if (flattenedBoard[next] != -1) {
                next = flattenedBoard[next] - 1;
            }
            if (dist[next] == -1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }
    return -1;
    }
};
