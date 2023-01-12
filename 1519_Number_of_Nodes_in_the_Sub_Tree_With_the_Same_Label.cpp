// You are given a tree (i.e. a connected, undirected graph that has no cycles) consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges. The root of the tree is the node 0, and each node of the tree has a label which is a lower-case character given in the string labels (i.e. The node with the number i has the label labels[i]).

// The edges array is given on the form edges[i] = [ai, bi], which means there is an edge between nodes ai and bi in the tree.

// Return an array of size n where ans[i] is the number of nodes in the subtree of the ith node which have the same label as node i.

// A subtree of a tree T is the tree consisting of a node in T and all of its descendant nodes.

// Example 1:
// Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], labels = "abaedcd"
// Output: [2,1,1,1,1,1,1]
// Explanation: Node 0 has label 'a' and its sub-tree has node 2 with label 'a' as well, thus the answer is 2. Notice that any node is part of its sub-tree.
// Node 1 has a label 'b'. The sub-tree of node 1 contains nodes 1,4 and 5, as nodes 4 and 5 have different labels than node 1, the answer is just 1 (the node itself).

// Example 2:
// Input: n = 4, edges = [[0,1],[1,2],[0,3]], labels = "bbbb"
// Output: [4,2,1,1]
// Explanation: The sub-tree of node 2 contains only node 2, so the answer is 1.
// The sub-tree of node 3 contains only node 3, so the answer is 1.
// The sub-tree of node 1 contains nodes 1 and 2, both have label 'b', thus the answer is 2.
// The sub-tree of node 0 contains nodes 0, 1, 2 and 3, all with label 'b', thus the answer is 4.

// Approach:
// Use DFS for Traversal
// Each node should return an array of size 26 to the parent, containing count of all labels in the subtree of that node.
// store that count for each node label in the output array
// Complexity:
// Time Complexity: O(n)
// Space Complexity: O(26*n)

class Solution {
public:
    vector<int> dfs(vector<vector<int>>&g,string &s,vector<int>&vis,int val,vector<int> &a){
		//We have a temp vector to keep the account of char in the sub trees
        vector<int>temp(26);
		//Making the visited node true or marking it visited
        vis[val]=1;
		
		//Now we start Traversing the neighboring nodes of the val node.
        for(int neig:g[val]){
		//We will call dfs only for the node which are not visited
            if(!vis[neig]){
                vector<int> child= dfs(g,s,vis,neig,a);
				
				//adding the label to the temp vector
                temp[s[neig]-'a']++;
				
				//adding the labels of all the subtree labels
                for(int i=0;i<26;i++){
                    temp[i]+=child[i];
                }
            }
        }
		//Finally adding temp value to the ans vector.
        a[val]+=temp[s[val]-'a']+1;
        return temp;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& e, string labels) {
        vector<vector<int>>g(n);
		//First step is to convert the edges into the graph
		//so as given undirected graph so we have made 2d vector for graph
        for(int i=0;i<e.size();i++){
            g[e[i][0]].push_back(e[i][1]);
            g[e[i][1]].push_back(e[i][0]);
        }
		//Second step is to make the visited vector 
		//inorder to keep the count of the node that has been visited.
        vector<int>vis(n),ans(n),temp(26);
        dfs(g,labels,vis,0,ans);
        return ans;
    }
};
