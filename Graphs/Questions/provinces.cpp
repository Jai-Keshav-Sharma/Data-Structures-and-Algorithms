// LeetCode 547. Number of Provinces

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, vector<int> adjList[], vector<int> &visited)
    {
        visited[node] = 1;

        for (auto it : adjList[node])
        {
            if (!visited[it])
            {
                dfs(it, adjList, visited);
            }
        }
    }

public:
    /**
     * @brief Finds the number of connected components (provinces) in a graph represented
     *        by an adjacency matrix.
     * 
     * @param isConnected A 2D vector representing the adjacency matrix of the graph,
     *                    where isConnected[i][j] = 1 indicates a direct connection
     *                    between node i and node j, and 0 indicates no connection.
     * 
     * @return int The number of connected components (provinces) in the graph.
     * 
     * @details The function first converts the adjacency matrix into an adjacency list
     *          representation for easier traversal. It then uses Depth First Search (DFS)
     *          to traverse the graph and count the number of connected components. Each
     *          unvisited node represents the start of a new connected component.
     */
    int findCircleNum(vector<vector<int>> &isConnected)
    {

        int n = isConnected.size();

        // converting into adjacency list
        vector<int> adjList[n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    adjList[i].push_back(j);
                }
            }
        }

        // solution
        vector<int> visited(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                cnt++;
                dfs(i, adjList, visited);
            }
        }

        return cnt;
    }
};