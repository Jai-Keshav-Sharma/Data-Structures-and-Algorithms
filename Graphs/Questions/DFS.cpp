#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /**
     * @brief Performs a Depth First Search (DFS) traversal starting from a given node.
     * 
     * This function recursively visits all the nodes in a graph that are reachable 
     * from the given starting node. It marks nodes as visited and stores the traversal 
     * order in the provided `dfs` vector.
     * 
     * @param node The current node being visited in the DFS traversal.
     * @param adj A reference to the adjacency list representation of the graph.
     *            Each index represents a node, and the vector at that index contains 
     *            the nodes adjacent to it.
     * @param vis A reference to a vector that keeps track of visited nodes. 
     *            A value of 1 indicates the node has been visited, and 0 indicates it has not.
     * @param dfs A reference to a vector that stores the order of nodes visited during the DFS traversal.
     */
    void solve(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &dfs)
    {
        vis[node] = 1;
        dfs.push_back(node);

        for (auto i : adj[node])
        {
            if (!vis[i])
            {
                solve(i, adj, vis, dfs);
            }
        }
    }

public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<int> vis(n, 0);
        vector<int> dfs;

        solve(0, adj, vis, dfs);

        return dfs;
    }
};
