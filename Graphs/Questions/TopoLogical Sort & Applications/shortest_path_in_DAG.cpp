#include <bits/stdc++.h>
using namespace std;

void topo(int node, vector<int> &vis, vector<vector<pair<int, int>>> &adj, stack<int> &st)
{
    vis[node] = 1;

    for (auto adjNode : adj[node])
    {
        int v = adjNode.first;
        if (!vis[v])
        {
            topo(v, vis, adj, st);
        }
    }

    st.push(node);
}

/**
 * @brief Computes the shortest path in a Directed Acyclic Graph (DAG) from a source node.
 * 
 * This function takes the number of nodes, the number of edges, and a list of edges with weights,
 * and returns a vector containing the shortest distances from the source node (assumed to be node 0)
 * to all other nodes in the graph. If a node is unreachable, its distance will be set to -1.
 * 
 * @param n The number of nodes in the graph.
 * @param m The number of edges in the graph.
 * @param edges A vector of vectors, where each inner vector represents an edge in the format 
 *              {u, v, wt}, indicating an edge from node u to node v with weight wt.
 * @return A vector of integers where the i-th element represents the shortest distance from 
 *         the source node (0) to node i. If a node is unreachable, its distance will be -1.
 * 
 * @note The graph must be a DAG (Directed Acyclic Graph) for this function to work correctly.
 *       The function uses topological sorting to process nodes in the correct order.
 */
vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v, wt});
    }

    stack<int> st;
    vector<int> vis(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            topo(i, vis, adj, st);
        }
    }

    vector<int> dist(n, INT_MAX);
    dist[0] = 0;

    while (st.top() != 0)
    {
        dist[st.top()] = -1;
        st.pop();
    }

    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        
        for (auto adjNode : adj[node])
        {
            int v = adjNode.first;
            int wt = adjNode.second;

            if (dist[node] + wt < dist[v])
            {
                dist[v] = dist[node] + wt;
            }
        }
    }

    return dist;
}