// There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
// Example 1:
// Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
// Output: 700
// Explanation:
// The graph is shown above.
// The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
// Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

#define pi pair<int, pair<int,int>>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Create an adjacency list to represent the flights
        vector<pair<int, int>> adj[n];
        for(auto it : flights){
            // for each flight, add an edge from the source city to the destination city with the price of the flight
            adj[it[0]].push_back({it[1], it[2]});
        }
        // Create a queue to store the current node, the number of stops, and the price
        queue<pi> q;
        // Create an array to store the minimum price to reach each city
        vector<int> dist(n, 1e9);
        // Add the source city with 0 stops and 0 cost {stops,{node, price}}
        q.push({0, {src, 0}});
        dist[src] = 0;
        // Loop through the queue until it is empty
        while(!q.empty()){
            int stop = q.front().first;
            int node = q.front().second.first, price = q.front().second.second;
            q.pop();
            // If the number of stops is greater than the allowed stops, continue
            if(stop > k) continue;
            // For each adjacent city, update the minimum price if a cheaper path is found
            for(auto it:adj[node]){
                int adjN = it.first;
                int Nprice = it.second;
                if(dist[adjN] > price + Nprice && stop<=k){
                    dist[adjN] = price + Nprice;
                    q.push({stop+1, {adjN, dist[adjN]}});
                }
            }
        }
        // If the minimum price to reach the destination is still the maximum value, return -1
        if(dist[dst]==1e9) return -1;
        // Otherwise, return the minimum price
        return dist[dst];
    }
};
