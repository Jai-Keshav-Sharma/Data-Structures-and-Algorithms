// LeetCode 207. Course Schedule
// Using TOPOLOGICAL SORT

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Determines if it is possible to finish all courses given the prerequisites.
 * 
 * This function checks for the presence of a cyclic dependency in a directed graph
 * where courses are represented as nodes and prerequisites as directed edges. If there
 * is no cycle, all courses can be completed; otherwise, it is not possible.
 * 
 * @param numCourses The total number of courses (vertices in the graph).
 * @param prerequisites A vector of pairs where each pair [a, b] indicates that course 'a'
 *        depends on course 'b' (a directed edge from 'b' to 'a').
 * @return true If all courses can be completed (no cyclic dependency).
 * @return false If there is a cyclic dependency preventing completion of all courses.
 * 
 * @note The function uses Kahn's Algorithm for Topological Sorting to detect cycles.
 *       - It constructs an adjacency list to represent the graph.
 *       - It calculates the in-degree of each node.
 *       - It uses a queue to process nodes with zero in-degree.
 *       - If the number of processed nodes equals the total number of courses, there
 *         is no cycle; otherwise, a cycle exists.
 * 
 * @time_complexity O(V + E), where V is the number of courses (vertices) and E is the
 *                  number of prerequisites (edges).
 * @space_complexity O(V + E), for the adjacency list and in-degree storage.
 */
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
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

    int cnt = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cnt++;

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

    // if cnt == # of jobs(Vertices) => no cyclic dependency present
    // jobs can be done fluently
    if (cnt == V)
        return true;

    // else Cyclic Dependency is present and all Jobs cant be completed
    return false;
}