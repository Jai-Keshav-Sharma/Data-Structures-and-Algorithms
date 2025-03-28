#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /**
     * @brief Performs a Depth First Search (DFS) to detect a cycle in a directed graph.
     * 
     * This function checks if there is a cycle in the graph by traversing the nodes
     * using DFS. It keeps track of visited nodes and the current path of visited nodes.
     * If a node is revisited in the same path, it indicates the presence of a cycle.
     * 
     * @param node The current node being visited.
     * @param adj The adjacency list representation of the graph.
     * @param vis An array to mark whether a node has been visited.
     * @param pathVis An array to mark whether a node is part of the current DFS path.
     * @return true If a cycle is detected in the graph.
     * @return false If no cycle is detected in the graph.
     */
    bool dfs(int node, vector<vector<int>> &adj, int vis[], int pathVis[])
    {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto adjNode : adj[node])
        {
            // if the adjNode has not been visited yet
            // visit it and include it in pathVisited
            if (!vis[adjNode])
            {
                if (dfs(adjNode, adj, vis, pathVis))
                {
                    return true;
                }
            }

            // if the adjNode has to be visited again in the same path
            // then there is a cycle and return true
            if (pathVis[adjNode] == 1)
            {
                return true;
            }
        }

        // backtracking
        pathVis[node] = 0;

        return false;
    }

public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(vector<vector<int>> &adj)
    {
        int n = adj.size();

        int vis[n] = {0};
        int pathVis[n] = {0};

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, adj, vis, pathVis))
                {
                    return true;
                }
            }
        }

        return false;
    }
};