// LeetCode 802. Find Eventual Safe States
// using DFS

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /**
     * @brief Performs a Depth First Search (DFS) to detect cycles in a directed graph
     *        and determine if a node is part of a cycle or leads to a cycle.
     * 
     * @param node The current node being visited.
     * @param vis A vector to keep track of visited nodes (1 if visited, 0 otherwise).
     * @param pathVis A vector to track nodes in the current DFS path (1 if in path, 0 otherwise).
     * @param safe A vector to mark nodes as safe (1 if safe, 0 otherwise).
     * @param adj The adjacency list representation of the graph.
     * @return true If a cycle is detected starting from the current node.
     * @return false If no cycle is detected starting from the current node.
     * 
     * @details
     * The function uses two auxiliary vectors, `vis` and `pathVis`, to detect cycles:
     * - `vis` ensures that each node is visited only once.
     * - `pathVis` tracks nodes in the current DFS path to detect back edges (indicating a cycle).
     * 
     * If a cycle is detected, the function returns true, marking the node as unsafe.
     * Otherwise, the node is marked as safe in the `safe` vector.
     * 
     * The function also backtracks by unmarking the node in `pathVis` after processing
     * all its adjacent nodes.
     */
    bool dfs(int node, vector<int> &vis, vector<int> &pathVis,
             vector<int> &safe, vector<vector<int>> &adj)
    {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto adjNode : adj[node])
        {
            // if the node is not visited yet
            // visit it and add to current path being visited
            if (!vis[adjNode])
            {
                // if there is a cycle
                // any node in the cycle or going into the cycle is not safe
                if (dfs(adjNode, vis, pathVis, safe, adj) == true)
                {
                    return true;
                }
            }
            // if the node has been visited previously in the same path, then
            // its a cycle
            if (pathVis[adjNode] == 1)
            {
                return true;
            }
        }

        // if the node is a terminal node, its safe
        safe[node] = 1;

        // if a cycle is detected, no node in the cycle unmarks it from current
        // path being visited, as a result, any node going into the cycle will
        // find the adjNode visited in current path and will not be safe, which
        // is true |
        // removing node from current path while backtracking
        pathVis[node] = 0;

        // no cycle is present
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int V = graph.size();

        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> safe(V, 0);
        vector<int> ans;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, pathVis, safe, graph);
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (safe[i] == 1)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};