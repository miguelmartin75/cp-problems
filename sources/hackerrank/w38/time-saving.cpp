#include <bits/stdc++.h>
using namespace std;

long leastTimeToInterview(int n, int k, int m) 
{
    vector<vector<pair<int, int>>> edges(n);
    for(int i = 0; i < m; ++i)
    {
        int u, v, t;
        cin >> u >> v >> t;

        if(u == v) continue;
        --u; --v;

        edges[u].emplace_back(v, t);
        edges[v].emplace_back(u, t);
    }

    using node = pair<int, int>;

    vector<int> dist(n, INT_MAX);
    dist[0] = 0;

    priority_queue<node, vector<node>, greater<node>> q;
    q.emplace(0, 0);

    while(!q.empty())
    {
        auto node = q.top();
        q.pop();

        int u = node.second;
        int t = node.first;

        int r = t % k;

        if(u + 1 == n)
        {
            return t;
        }

        for(auto& vv : edges[u])
        {
            int v = vv.first;
            int w = vv.second;
            int pos = (r + w) % (2*k);
            if(v + 1 != n && pos >= k)
            {
                w += 2*k - pos;
            }

            if(w + t < dist[v])
            {
                dist[v] = w + t;
                q.emplace(w + t, v);
            }
        }
    }

    return -1;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k, m;
    cin >> n >> k >> m;

    long result = leastTimeToInterview(n, k, m);

    cout << result << "\n";
}
