#include <iostream>
#include <bits/stdc++.h>

using namespace std;
bool bipartiteBFS(int src, vector<int> adj[], int color[])
{
    queue<int> q;
    q.push(src);
    color[src] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if (color[it] == color[node])
                return false;
        }
    }
    return true;
}
bool checkBipartite(int n, vector<int> adj[])
{
    int color[n];
    memset(color, -1, sizeof color);

    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!bipartiteBFS(i, adj, color))
                return false;
        }
    }
    return true;
}
int main()
{
    int n;
    int m;

    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (checkBipartite(n, adj))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
