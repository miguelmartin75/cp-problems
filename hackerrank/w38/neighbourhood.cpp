#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int d, vector<vector<int>>& edges, vector<int>& a, vector<bool>& visited, vector<int>& arr)
{
    if(d == 0) 
    {
        arr.push_back(a[u]);
        return;
    }

    arr.push_back(a[u]);
    visited[u] = true;

    for(int v : edges[u])
    {
        if(visited[v]) continue;
        dfs(v, d - 1, edges, a, visited, arr);
    }
}

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a;
    a.reserve(n);
    for(int i = 0; i < n; ++i) { int x; cin >> x; a.push_back(x); }

    vector<vector<int>> e(n);
    for(int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; ++i)
    {
        int u, d, k;
        cin >> u >> d >> k;

        vector<bool> visited(n, false);
        vector<int> temp;
        dfs(u - 1, d, e, a, visited, temp);

        --k;

        if(k >= temp.size())
            cout << -1 << '\n';
        else
        {
            nth_element(temp.begin(), temp.begin() + k, temp.end());
            cout << temp[k] << '\n';
        }
    }
}
