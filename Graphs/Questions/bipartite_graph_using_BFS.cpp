// LeetCode 785. Is Graph Bipartite?

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /**
     * @brief Performs a Breadth-First Search (BFS) to check if a graph is bipartite starting from a given node.
     * 
     * @param start The starting node for the BFS traversal.
     * @param adj A reference to the adjacency list representation of the graph.
     * @param color An array used to store the color of each node (-1 indicates unvisited, 0 and 1 are the two colors).
     * @return true If the graph is bipartite starting from the given node.
     * @return false If the graph is not bipartite.
     * 
     * @details
     * This function uses BFS to traverse the graph and assigns colors to nodes such that no two adjacent nodes
     * have the same color. If it encounters a situation where two adjacent nodes have the same color, it concludes
     * that the graph is not bipartite and returns false. Otherwise, it returns true.
     * 
     * The function assumes that the `color` array is initialized with -1 for all nodes before calling this function.
     * 
     * Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
     * Space Complexity: O(V), for the queue and color array.
     */
    bool bfs(int start, vector<vector<int>> &adj, int *color)
    {
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto adjNode : adj[node])
            {
                // adjNode is not visited yet and not been assigned a color
                if (color[adjNode] == -1)
                {
                    color[adjNode] = !color[node];
                    q.push(adjNode);
                }

                // adjNode has been visited and assigned a color in some other
                // path and has the same color as current node => not bipartite
                if (color[adjNode] == color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();

        int color[n];
        for (int i = 0; i < n; i++)
            color[i] = -1;

        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (!bfs(i, graph, color))
                {
                    return false;
                }
            }
        }
        return true;
    }
};