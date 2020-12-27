#include <bits/stdc++.h>
using namespace std;

const int INF = (1 << 30);

int n;
int adj[201][201] = {};
int cache[201][201] = {};

int dist(int i, int j)
{
    if(cache[i][j] != 0) return cache[i][j];
    auto cmp = [](auto& x, auto& y) { return x.second > y.second; };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
    q.emplace(i, 0);

    bool visited[201] = {};

    while(!q.empty())
    {
        auto k = q.top();
        q.pop();

        const int node = k.first;
        const int dist = k.second;

        visited[node] = true;

        if(node == j)
        {
            cache[i][j] = dist;
            cache[j][i] = dist;
            return dist;
        }

        for(int i = 0; i < 200; ++i)
        {
            if(visited[i] || adj[node][i] == 0) continue;
            q.emplace(i, dist + adj[node][i]);
        }
    }

    return INF;
}

int main(int argc, char *argv[])
{
    cin.sync_with_stdio(false);
    cin.tie(0);

    int m, r;
    cin >> n >> m >> r;

    vector<int> nodes(r);
    for(int i = 0; i < r; ++i)
    {
        cin >> nodes[i];
        nodes[i]--;
    }

    for(int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a -= 1;
        b -= 1;

        if(adj[a][b] == 0)
        {
            adj[a][b] = c;
            adj[b][a] = c;
        }
    }

    sort(nodes.begin(), nodes.end());

    int min_dist = numeric_limits<int>::max();
    do
    {
        int curr_dist = 0;
        for(int i = 1; i < nodes.size(); ++i)
        {
            const int from = nodes[i - 1];
            const int to = nodes[i];
            const int D = dist(from, to);
            curr_dist += D;
        }
        min_dist = min(curr_dist, min_dist);
    } while(next_permutation(nodes.begin(), nodes.end()));

    cout << min_dist << endl;
}
