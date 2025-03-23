#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /**
     * @brief Detects a cycle in an undirected graph using BFS.
     * 
     * This function checks for the presence of a cycle in an undirected graph
     * starting from a given source node. It uses a queue to perform a Breadth-First
     * Search (BFS) and keeps track of visited nodes and their parent nodes.
     * 
     * @param src The source node from which to start the BFS.
     * @param adjList The adjacency list representation of the graph.
     * @param visited A reference to a vector that keeps track of visited nodes.
     *                Each element is 1 if the corresponding node is visited, 0 otherwise.
     * @return true If a cycle is detected in the graph.
     * @return false If no cycle is detected in the graph.
     */
    bool solve(int src, vector<vector<int>> adjList, vector<int> &visited)
    {
        queue<pair<int, int>> q;
        q.push({src, -1});
        visited[src] = 1;

        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto adjNode : adjList[node])
            {
                if (!visited[adjNode])
                {
                    visited[adjNode] = 1;
                    q.push({adjNode, node});
                }
                else if (adjNode != parent)
                {
                    return true;
                }
            }
        }
        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>> &adj)
    {
        int n = adj.size();
        int m = adj[0].size();

        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (solve(i, adj, visited))
                    return true;
            }
        }
        return false;
    }
};