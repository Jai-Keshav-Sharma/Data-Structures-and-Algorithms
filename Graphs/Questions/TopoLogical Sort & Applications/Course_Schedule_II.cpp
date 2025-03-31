// LeetCode 210. Course Schedule II

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds the order of courses to complete all courses given the prerequisites.
 * 
 * This function determines a valid order in which courses can be completed based on 
 * the given prerequisites using Kahn's Algorithm (Topological Sorting). If it is not 
 * possible to complete all courses due to a cyclic dependency, it returns an empty vector.
 * 
 * @param numCourses The total number of courses (vertices in the graph).
 * @param prerequisites A vector of pairs where each pair [a, b] indicates that course 'a' 
 *                      depends on course 'b' (a directed edge from b to a).
 * @return A vector of integers representing the order in which courses can be completed. 
 *         If no valid order exists (cyclic dependency), returns an empty vector.
 * 
 * @note The function assumes that courses are labeled from 0 to numCourses - 1.
 * 
 * @example
 * Input: numCourses = 4, prerequisites = [[1, 0], [2, 0], [3, 1], [3, 2]]
 * Output: [0, 1, 2, 3] or [0, 2, 1, 3]
 * Explanation: To complete course 3, you need to complete courses 1 and 2. 
 *              Course 1 depends on course 0, and course 2 depends on course 0.
 *              A valid order is [0, 1, 2, 3] or [0, 2, 1, 3].
 */
vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    int V = numCourses;

    // forming the adjacency List
    vector<vector<int>> adj(V);
    for (auto it : prerequisites)
    {
        adj[it[1]].push_back(it[0]);
    }

    // storing the indegrees of nodes
    vector<int> indeg(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indeg[it]++;
        }
    }

    // nodes with indegree pushed into q
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for (auto adjNode : adj[node])
        {
            // removing nodes contribution in indegrees of its nbrs
            indeg[adjNode]--;

            // if indeg[adjNode] == 0, push into q
            if (indeg[adjNode] == 0)
            {
                q.push(adjNode);
            }
        }
    }

    // if ans.size() == # of jobs(Vertices) => no cyclic dependency present
    // jobs can be done fluently
    if (ans.size() == V)
        return ans;

    // else Cyclic Dependency is present and all Jobs cant be completed
    return {};
}