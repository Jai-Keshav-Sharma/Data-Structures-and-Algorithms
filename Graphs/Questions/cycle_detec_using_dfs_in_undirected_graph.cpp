#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /**
     * @brief Detects a cycle in an undirected graph using Depth First Search (DFS).
     * 
     * This function recursively traverses the graph starting from the given source node
     * and checks for the presence of a cycle. It uses a visited array to keep track of
     * visited nodes and ensures that backtracking does not falsely detect a cycle by 
     * considering the parent node of the current node.
     * 
     * @param src The current node being visited in the graph.
     * @param adjList The adjacency list representation of the graph.
     * @param visited A reference to a vector that keeps track of visited nodes.
     * @param parent The parent node of the current node in the DFS traversal.
     * @return true If a cycle is detected in the graph.
     * @return false If no cycle is detected in the graph.
     */
    bool solve(int src, vector<vector<int>> adjList, vector<int> &visited, int parent)
    {
        visited[src] = 1;

        for (auto adjNode : adjList[src])
        {
            if (!visited[adjNode])
            {
                if (solve(adjNode, adjList, visited, src))
                {
                    return true;
                }
            }
            else if (adjNode != parent)
            {
                return true;
            }
        }
        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>> &adj)
    {
        int n = adj.size();

        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (solve(i, adj, visited, -1))
                    return true;
            }
        }
        return false;
    }
};
