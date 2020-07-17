#include <vector>
using namespace std;

class Solution {
public:
    void findBridges(int curr, int& timer, vector<vector<int>>& g,
                    vector<bool>& visited, vector<int>& earliest_back_edge,
                    vector<int>& discovery_time,
                    vector<vector<int>>& bridges,
                    int parent = -1) {
        
        // mark as visited
        visited[curr] = true;
        discovery_time[curr] = earliest_back_edge[curr] = timer++;
        
        // for all its neighbors check if they have a back edge
        for(int v: g[curr]) {
            if(!visited[v]) {
                findBridges(v, timer, g,
                        visited, earliest_back_edge,
                        discovery_time, bridges, curr);
                
                // check if the subtree has a back edge with discovery time lesser than current vertex
                earliest_back_edge[curr] = min(earliest_back_edge[curr], earliest_back_edge[v]);
                // if the subtree doesnt have a back edge before or with current node,
                // then the current edge is a bridge
                if(earliest_back_edge[v] > discovery_time[curr])
                    bridges.emplace_back(vector<int>{curr, v});
            }
            // node was visited before and not parent, means it comes before current node
            else if(visited[v] && parent != v)
                earliest_back_edge[curr] = min(earliest_back_edge[curr], discovery_time[v]);
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Create a graph
        vector<vector<int>> g(n);
        for(const auto& edge: connections) {
            g[edge[0]].emplace_back(edge[1]);
            g[edge[1]].emplace_back(edge[0]);
        }
        
        // Find all the bridges
        int timer = 1;
        vector<bool> visited(n, false);
        vector<int> earliest_back_edge(n, INT_MAX), discovery_time(n, -1);
        vector<vector<int>> bridges;
        
        for(int i = 0; i < n; i++)
            if(!visited[i])
                findBridges(i, timer, g, visited,
                           earliest_back_edge, 
                            discovery_time, bridges);
        return bridges;
    }
};