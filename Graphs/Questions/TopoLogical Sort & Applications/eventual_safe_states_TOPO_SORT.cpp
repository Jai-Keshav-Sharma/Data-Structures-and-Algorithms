// LeetCode 802. Find Eventual Safe States

#include <bits/stdc++.h>
using namespace std;

// USING TOPO SORT
/**
 * @brief Finds all the eventual safe nodes in a directed graph using topological sorting.
 * 
 * An eventual safe node is a node that can only reach terminal nodes (nodes with no outgoing edges)
 * or other eventual safe nodes. This function identifies such nodes by reversing the graph's edges
 * and performing a topological sort based on indegrees.
 * 
 * @param graph A directed graph represented as an adjacency list, where graph[i] contains a list
 *              of nodes that node i has edges to.
 * @return A vector of integers containing the indices of all eventual safe nodes, sorted in ascending order.
 * 
 * @note The algorithm works by:
 *       1. Reversing the edges of the graph and calculating the indegree of each node after reversal.
 *       2. Using a queue to perform a topological sort, starting with nodes that have an indegree of 0.
 *       3. Collecting nodes in the topological order and sorting them to return the result.
 * 
 * @complexity
 * Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
 * Space Complexity: O(V + E), for storing the reversed graph and the indegree array.
 */
vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int V = graph.size();

    // reversing the edges
    // and storing the indegrees after reversal
    vector<vector<int>> adj(V);
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto it : graph[i])
        {
            adj[it].push_back(i);
            indegree[i]++;
        }
    }

    // pushing nodes with 0 indegree in to q
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // TOPO SORT
    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for (auto adjNode : adj[node])
        {
            indegree[adjNode]--;

            if (indegree[adjNode] == 0)
            {
                q.push(adjNode);
            }
        }
    }

    // sorting in ascending order
    sort(ans.begin(), ans.end());
    return ans;
}