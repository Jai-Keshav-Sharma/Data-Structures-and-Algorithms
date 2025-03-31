#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Performs topological sorting on a directed acyclic graph (DAG) using Kahn's Algorithm.
 * 
 * @param adj A reference to the adjacency list representation of the graph.
 *            adj[i] contains a list of all nodes that have an edge from node i.
 * @return A vector of integers representing the topological order of the nodes.
 *         If the graph is not a DAG, the result may be incomplete or invalid.
 * 
 * @details
 * The function calculates the in-degree of each node and uses a queue to process
 * nodes with zero in-degree. It iteratively removes nodes from the graph by
 * reducing the in-degree of their adjacent nodes and adding nodes with zero
 * in-degree to the queue. The process continues until all nodes are processed
 * or the queue becomes empty.
 * 
 * @note This function assumes the input graph is a DAG. If the graph contains
 *       cycles, the topological sort will not include all nodes.
 * 
 * @complexity
 * Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
 * Space Complexity: O(V), for storing the in-degree array, queue, and result vector.
 */
vector<int> topologicalSort(vector<vector<int>> &adj)
{
    int n = adj.size();

    // getting indegrees of all nodes
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    // pushing into q, the nodes with 0 indegree
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        // pushing the node into topo list
        topo.push_back(node);

        // removing the indegree contribution of current node from its adjacent nodes
        // as we have pushed it into topo
        for (auto adjNode : adj[node])
        {
            indegree[adjNode]--;

            // if any adjNode has indegree 0, push it into q
            if (indegree[adjNode] == 0)
            {
                q.push(adjNode);
            }
        }
    }

    return topo;
}