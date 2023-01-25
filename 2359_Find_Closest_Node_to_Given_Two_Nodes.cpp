// You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.
// The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from i, then edges[i] == -1.
// You are also given two integers node1 and node2.
// Return the index of the node that can be reached from both node1 and node2, such that the maximum between the distance from node1 to that node, and from node2 to that node is minimized. If there are multiple answers, return the node with the smallest index, and if no possible answer exists, return -1.
// Note that edges may contain cycles.

// Example 1:
// Input: edges = [2,2,3,-1], node1 = 0, node2 = 1
// Output: 2
// Explanation: The distance from node 0 to node 2 is 1, and the distance from node 1 to node 2 is 1.
// The maximum of those two distances is 1. It can be proven that we cannot get a node with a smaller maximum distance than 1, so we return node 2.
// Approach
// Initialize variables n to the size of the edges array, ans to -1, and minDist to the maximum value of an int.
// Create two arrays dist1 and dist2 of size n and initialize all elements to 0. Also, create two arrays visited1 and visited2 of size n and initialize all elements to false.
// Run the depth-first search (DFS) algorithm from node1 and update the dist1 and visited1 arrays accordingly.
// Run the DFS algorithm from node2 and update the dist2 and visited2 arrays accordingly.
// Iterate through all nodes currNode in the graph.
// For each node, check if it has been visited by both DFS calls, and if its maximum distance from node1 and node2 (i.e. max(dist1[currNode], dist2[currNode])) is less than the current value of minDist.
// If the above conditions are met, update the value of minDist and ans to the current node's distance and index, respectively.
// Return ans as the result.
// This algorithm finds the closest meeting point between two given nodes in a graph by using DFS to calculate the distance from each node to all other nodes in the graph. It only considers nodes that are reachable from both given nodes, and chooses the one that has the smallest maximum distance from the two given nodes.


class Solution {
public:
    void dfs(int node, vector<int>& edges, vector<int>& distance, vector<bool>& visited){
        visited[node] = true;
        int neighbor = edges[node];
        if (neighbor != -1 && visited[neighbor] == false) {
            distance[neighbor] = distance[node] + 1;
            dfs(neighbor, edges, distance, visited);
        }
    }
    //we are using DFS to solve this problem
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        int ans = -1;
        int minDist = INT_MAX;
        //dist1 store the distance from node1 to all the neighbour nodes and dist2 store the distance from node2 to all the neighbour nodes
        vector<int> dist1(n, 0), dist2(n, 0);
        //visited array helps us to identify wheather we visited to particular node form node1 or not similarly for visited2
        vector<bool> visited1(n, false), visited2(n, false);
        //calling dfs from both the nodes i.e. node1 and node2
        dfs(node1, edges, dist1, visited1);
        dfs(node2, edges, dist2, visited2);

        for(int currNode = 0; currNode < n; currNode++){
            if(visited1[currNode] == true && visited2[currNode] == true && minDist > max(dist1[currNode], dist2[currNode])){
                minDist = max(dist1[currNode], dist2[currNode]);
                ans = currNode;
            }
        }
        return ans;
    }
};
