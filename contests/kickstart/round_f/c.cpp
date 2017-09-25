#include <bits/stdc++.h>
using namespace std;

int n;
int dist[100+1][100+1] = {};

map<pair<int, int>, float> result;

float solve(int p, int i)
{
    //if(result.count(make_pair(p, i)))
    {
        //return result[make_pair(p, i)];
    }

    if(p == 0) return 0;
    float sum = 0;
    for(int j = 1; j <= n; ++j)
    {
        if(i == j) continue;
        sum += dist[i][j];
        sum += solve(p - 1, j);
    }
    sum /= n - 1;
    result[make_pair(p, i)] = sum;
    return sum;
}

int main(int argc, char *argv[])
{
    int t;
    cin >> t;

    cout << fixed << setprecision(4);
    for(int i = 0; i < t; ++i)
    {
        int m, p;
        cin >> n >> m >> p;

        result.clear();
        for(int i = 0; i < 101; ++i)
            for(int j = 0; j < 101; ++j)
                dist[i][j] = i == j ? 0 : 100000;

        for(int i = 0; i < m; ++i)
        {
            int x, y, w;
            cin >> x >> y >> w;
            dist[x][y] = dist[y][x] = w;
        }

        for(int k = 1; k <= n; ++k)
            for(int i = 1; i <= n; ++i)
                for(int j = 1; j <= n; ++j)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        vector<float> total_dist(n, 0.f);
        for(int i = 1; i <= n; ++i)
        {
            float sum = 0.f;
            for(int j = 1; j <= n; ++j)
            {
                sum += dist[i][j];
            }
            total_dist[i - 1] = sum;
        }

        vector<float> prev(n, 0.f);
        vector<float> next(n, 0);
        float total_prev = 0.f;
        for(int x = 0; x < p; ++x)
        {
            float total_next = 0.f;
            for(int i = 1; i <= n; ++i)
            {
                float sum = total_dist[i - 1];
                sum += total_prev - prev[i - 1];
                sum /= n - 1;
                next[i - 1] = sum;
                total_next += sum;
            }
            swap(next, prev);
            total_prev = total_next;
        }

        cout << "Case #" << i + 1 << ": " << prev[0] << '\n';
    }
    cout << flush;
}
