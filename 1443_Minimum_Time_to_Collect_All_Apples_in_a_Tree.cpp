// Given an undirected tree consisting of n vertices numbered from 0 to n-1, which has some apples in their vertices. You spend 1 second to walk over one edge of the tree. Return the minimum time in seconds you have to spend to collect all apples in the tree, starting at vertex 0 and coming back to this vertex.

// The edges of the undirected tree are given in the array edges, where edges[i] = [ai, bi] means that exists an edge connecting the vertices ai and bi. Additionally, there is a boolean array hasApple, where hasApple[i] = true means that vertex i has an apple; otherwise, it does not have any apple.

 

// Example 1:


// Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
// Output: 8 
// Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.  
// Example 2:


// Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,false,true,false]
// Output: 6
// Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.  
// Example 3:

// Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,false,false,false,false,false]
// Output: 0
 

// Constraints:

// 1 <= n <= 105
// edges.length == n - 1
// edges[i].length == 2
// 0 <= ai < bi <= n - 1
// fromi < toi
// hasApple.length == n

class Solution {
    vector<bool> vis;
    int dfs(int i, int &appleCount, vector<vector<int>>& graph, vector<bool>& hasApple){
        vis[i] = 1;

        int time = 0;

        // Traversing all adjacent node which are not visited
        for(auto j : graph[i]){
            int appleCount1 = 0;
            if(vis[j] == false){
                int time1 = dfs(j, appleCount1, graph, hasApple);

                // Adding time only if traversed subtree branch has more than 0 apples
                if(appleCount1 != 0){  
                    time += time1;
                    appleCount += appleCount1;
                }
            }
        }

        if(hasApple[i] == true)
            count++;
        
        // Returning total no. of times edges traversed in this subtree + Edges traversed from parent node to this node
        return time+2;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vis = vector<bool>(n, false);

        // Building graph
        vector<vector<int>> graph(n);
        for(auto edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int appleCount = 0;

        // Counting extra 2 then need to decrease it
        return dfs(0, appleCount, graph, hasApple) - 2;
    }
};
