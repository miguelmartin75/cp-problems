#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int gcd(int n, int m)
{
    if(m == 0) return n;
    return gcd(m, n % m);
}

map<int, bool> visited;
void dfs(int u, vector<int>& val, vector<vector<int>>& edges, map<int, ll>& counts, map<int, vector<int>>& cache)
{
    visited[u] = true;

    vector<int> result = { val[u] };
    counts[val[u]]++;

    vector<int> temp;
    for(int v : edges[u])
    {
        if(visited[v])
            continue;

        dfs(v, val, edges, counts, cache);
        for(int g : cache[v])
        {
            //cout << u + 1 << " to g = " << g << endl;
            temp.push_back(g);
            int res = gcd(g, val[u]);
            counts[res]++;
            result.push_back(res);
        }
    }
    cache[u] = result;

    if(edges[u].size() > 1)
        for(int i = 0; i < temp.size(); ++i)
        {
            for(int j = i + 1; j < temp.size(); ++j)
            {
                int res = gcd(val[u], gcd(temp[i], temp[j]));
                //counts[res]++;
            }
        }
}

map<int, ll> count(int n, vector<int>& val, vector<vector<int>>& edges)
{
    map<int, ll> result;
    map<int, vector<int>> cache;
    for(int i = 0; i < n; ++i)
    {
        if(visited[i]) continue;
        if(edges[i].size() == 1)
            dfs(i, val, edges, result, cache);
    }
    return result;
}

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int& x : a) cin >> x;

    vector<vector<int>> edges(n);
    for(int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        edges[u - 1].push_back(v - 1);
        edges[v - 1].push_back(u - 1);
    }

    //for(int i = 0; i < edges.size(); ++i)
    //{
    //    cout << i << " => ";
    //    for(int x : edges[i]) cout << x << " ";
    //    cout << endl;
    //}

    //cout << endl;

    auto c = count(n, a, edges);
    for(auto& y : c)
    {
        cout << y.first << ' ' << y.second << '\n';
    }
    cout << endl;
}
