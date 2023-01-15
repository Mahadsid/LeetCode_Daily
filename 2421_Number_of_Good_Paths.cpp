There is a tree (i.e. a connected, undirected graph with no cycles) consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges.

You are given a 0-indexed integer array vals of length n where vals[i] denotes the value of the ith node. You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

A good path is a simple path that satisfies the following conditions:

The starting node and the ending node have the same value.
All nodes between the starting node and the ending node have values less than or equal to the starting node (i.e. the starting node's value should be the maximum value along the path).
Return the number of distinct good paths.

Note that a path and its reverse are counted as the same path. For example, 0 -> 1 is considered to be the same as 1 -> 0. A single node is also considered as a valid path.

 

Example 1:


Input: vals = [1,3,2,1,3], edges = [[0,1],[0,2],[2,3],[2,4]]
Output: 6
Explanation: There are 5 good paths consisting of a single node.
There is 1 additional good path: 1 -> 0 -> 2 -> 4.
(The reverse path 4 -> 2 -> 0 -> 1 is treated as the same as 1 -> 0 -> 2 -> 4.)
Note that 0 -> 2 -> 3 is not a good path because vals[2] > vals[0].

class Solution {
public:
    // function to find the parent of a given element in the union-find data structure
    int find(vector<int>& parent, int a) {
        // if the element is its own parent, return the element
        if(parent[a] == a)
            return a;
        // otherwise, set the parent of the element to be the parent of its parent and return that parent
        parent[a] = find(parent, parent[a]);
        return parent[a];
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        // create a vector to store the parents of each element
        vector<int> parent(n);
        // create maps to store the maximum element and count of elements in each connected component
        map<int,int> maxel;
        map<int, int> count;

        // initialize the parent vector and maps
        for(int i=0;i<n;i++){
            parent[i] = i;
            maxel[i] = vals[i];
            count[i] = 1;
        }

        // sort the edges based on the maximum value of the vertices in the edge
        sort(edges.begin(), edges.end(), [&](const vector<int>& a, vector<int>& b)
        {
            int m = max(vals[a[0]], vals[a[1]]);
            int n = max(vals[b[0]], vals[b[1]]);
            return m<n;
        });
        int ans=n;
        // for each edge, find the connected components of the vertices and union them
        for(auto edge : edges){
            int a = find(parent, edge[0]);
            int b = find(parent, edge[1]);
            if(maxel[a] != maxel[b]){
                // if the maximum element in the two connected components is different, set the parent of the connected component with smaller maximum value to be the parent of the connected component with the larger maximum value
                if(maxel[a] > maxel[b])
                    parent[b] = a;
                else
                    parent[a] = b;
            }
            else{
                // if the maximum element in the two connected components is the same, set the parent of the connected component with the smaller index to be the parent of the connected component with the larger index, and update the count of the new connected component
                parent[a] = b;
                ans += count[a] * count[b];
                count[b] += count[a];
            }
        }
        // return the total number of connected components plus the number of good paths
        return ans;
    }
};
