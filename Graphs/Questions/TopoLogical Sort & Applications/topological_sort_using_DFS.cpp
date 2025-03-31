#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /**
     * @brief Performs a Depth First Search (DFS) traversal on a graph and 
     *        computes the topological order by using a stack.
     * 
     * @param node The current node being visited in the DFS traversal.
     * @param vis A reference to a vector that keeps track of visited nodes.
     *            Each index represents a node, and its value is 1 if visited, 0 otherwise.
     * @param adj A reference to the adjacency list of the graph, where each index 
     *            represents a node and contains a list of its adjacent nodes.
     * @param st A reference to a stack used to store nodes in topological order.
     *           Nodes are pushed onto the stack after all their adjacent nodes 
     *           have been visited.
     */
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st)
    {
        vis[node] = 1;

        for (auto adjNode : adj[node])
        {
            if (!vis[adjNode])
            {
                dfs(adjNode, vis, adj, st);
            }
        }

        st.push(node);
    }

public:
    // Function to return list containing vertices in Topological order.
    /**
     * @brief Performs topological sorting on a directed acyclic graph (DAG) using Depth First Search (DFS).
     * 
     * @param adj A reference to the adjacency list representation of the graph.
     *            Each index represents a node, and the vector at that index contains
     *            the nodes it points to.
     * @return A vector of integers representing the topological order of the nodes.
     *         If the graph is not a DAG, the behavior is undefined.
     * 
     * @note This function assumes that the graph is a DAG. If the graph contains cycles,
     *       the result will not be a valid topological order.
     * 
     * @complexity
     * Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
     * Space Complexity: O(V), for the visited array, stack, and result vector.
     */
    vector<int> topologicalSort(vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<int> vis(n, 0);

        stack<int> st;
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj, st);
            }
        }

        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};