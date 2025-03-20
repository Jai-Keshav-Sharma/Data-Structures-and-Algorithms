#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Performs Breadth-First Search (BFS) traversal on a graph represented as an adjacency list.
 * 
 * @param adj A reference to a 2D vector representing the adjacency list of the graph.
 *            Each index represents a node, and the vector at that index contains the nodes
 *            it is connected to.
 * 
 * @return A vector of integers representing the BFS traversal order of the graph starting from node 0.
 * 
 * @note Assumes the graph is connected and the traversal starts from node 0.
 *       If the graph is not connected, only the connected component containing node 0 will be traversed.
 *       The graph is represented as a zero-indexed adjacency list.
 */
vector<int> bfsOfGraph(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> visited(n, 0);
    vector<int> bfs;

    queue<int> q;
    q.push(0);
    visited[0] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        bfs.push_back(node);

        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}