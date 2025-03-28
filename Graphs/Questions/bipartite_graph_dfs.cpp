// LeetCode 785. Is Graph Bipartite?

#include <bits/stdc++.h>
using namespace std;

class Solution
{   
private:
    /**
     * @brief Performs a Depth First Search (DFS) to check if a graph is bipartite.
     * 
     * This function recursively traverses the graph using DFS and assigns colors
     * to nodes to determine if the graph is bipartite. A graph is bipartite if it
     * is possible to divide its set of vertices into two disjoint sets such that
     * no two graph vertices within the same set are adjacent.
     * 
     * @param start The starting node for the DFS traversal.
     * @param adj The adjacency list representation of the graph.
     * @param color A vector used to store the color of each node. 
     *              -1 indicates unvisited, 0 and 1 are the two colors.
     * @param col The color to assign to the current node.
     *            It alternates between 0 and 1 during the traversal.
     * @return true If the graph is bipartite starting from the given node.
     * @return false If the graph is not bipartite.
     */
    bool dfs(int start, vector<vector<int>> &adj, vector<int> &color, int col)
    {
        color[start] = col;

        for (auto it : adj[start])
        {
            // if the adjNode is not visited yet
            // give it the opposite color of present node
            if (color[it] == -1)
            {
                if (!dfs(it, adj, color, !col))
                {
                    return false;
                }

                // if adjNode is already visited
                // and has same color as present node => not bipartite
            }
            else if (color[it] == col)
            {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();

        vector<int> color(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (!dfs(i, graph, color, 0))
                {
                    return false;
                }
            }
        }
        return true;
    }
};