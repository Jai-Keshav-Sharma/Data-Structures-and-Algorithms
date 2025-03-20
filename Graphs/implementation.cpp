#include <bits/stdc++.h>
using namespace std;

// NOTE: the nodes in graph are supposed to have 1 based indexing

// implementation using matrix of UNDIRECTED graph ---- O(E x E) space
void UndirectedUsingMatrix()
{
    int n;
    int m;

    cin >> n >> m;

    int adj[n + 1][n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}

// undirected graphs using List ---- O(V + E) Space
void UndirectedUsingList()
{
    int n;
    int m;

    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

// directed graphs using List ---- O(E)
void DirectedUsingList()
{
    int n;
    int m;

    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }
}

// weighted undirected graph using list
void weightedUndirectedUsingList()
{
    int n;
    int m;

    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
}

// weighted directed graph using list
void weightedDirectedUsingList()
{
    int n;
    int m;

    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
    }
}