// Using Topological Sort ( Kahn's Algorithm )

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Detects if there is a cycle in a directed graph using Kahn's Algorithm (BFS-based approach).
 * 
 * This function checks for the presence of a cycle in a directed graph by performing a topological sort.
 * If the number of nodes in the topological order is less than the total number of nodes, it indicates
 * the presence of a cycle.
 * 
 * @param adj A reference to the adjacency list representation of the directed graph.
 *            adj[i] contains a list of all nodes that have an edge from node i.
 * 
 * @return true If the graph contains a cycle.
 * @return false If the graph does not contain a cycle.
 * 
 * @note The function assumes that the graph is represented as a zero-indexed adjacency list.
 *       It uses a queue to process nodes with zero in-degree and iteratively reduces the in-degree
 *       of their adjacent nodes.
 * 
 * @complexity
 * Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
 * Space Complexity: O(V), for storing the in-degree array and the queue.
 */
bool isCyclic(vector<vector<int>> &adj)
{
    int n = adj.size();

    // storing ingedrees of nodes
    vector<int> indeg(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            indeg[it]++;
        }
    }

    // pushing node with indeg == 0 in the q
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }

    // cnt will store the count of nodes in the Topological Order
    int cnt = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cnt++;

        for (auto adjNode : adj[node])
        {
            // removing current nodes contribution in indegrees of its
            // adjcent nodes
            indeg[adjNode]--;

            // if indeg of any if the adjacent nodes becomes zero
            // push it into q
            if (indeg[adjNode] == 0)
            {
                q.push(adjNode);
            }
        }
    }

    // if cnt == number of nodes, then there is no cycle as Topo sort works only
    // on DAGs
    if (n == cnt)
    {
        return false;
    }

    return true;
}