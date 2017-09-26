#include <bits/stdc++.h>
using namespace std;

int dist[100][100] = {};

vector<vector<double>> mat_mul(const vector<vector<double>>& m1, const vector<vector<double>>& m2)
{
    vector<vector<double>> res;
    for(int i = 0; i < m1.size(); ++i)
    {
        vector<double> temp;
        for(int j = 0; j < m2[0].size(); ++j)
        {
            double mul = 0.f;
            for(int k = 0; k < m2.size(); ++k)
            {
                mul += m1[i][k] * m2[k][j];
            }
            temp.push_back(mul);
        }
        res.push_back(temp);
    }
    return res;
}

vector<vector<double>> mat_pow(const vector<vector<double>>& mat, int n)
{
    if(n == 0)
    {
        vector<vector<double>> new_mat;
        for(int i = 0; i < mat.size(); ++i)
        {
            vector<double> row;
            for(int j = 0; j < mat.size(); ++j)
            {
                row.push_back(i == j ? 1 : 0);
            }
            new_mat.push_back(row);
        }
        return new_mat;
    }
    if(n == 1) { return mat; }
    if(n % 2 == 0)
    {
        auto new_mat = mat_pow(mat, n/2);
        return mat_mul(new_mat, new_mat);
    }
    else
    {
        return mat_mul(mat_pow(mat, n - 1), mat);
    }
}

int main(int argc, char *argv[])
{
    int t;
    cin >> t;

    cout << fixed << setprecision(4);
    for(int i = 0; i < t; ++i)
    {
        int n, m, p;
        cin >> n >> m >> p;

        for(int i = 0; i < 100; ++i)
            for(int j = 0; j < 100; ++j)
                dist[i][j] = i == j ? 0 : 100000;

        for(int i = 0; i < m; ++i)
        {
            int x, y, w;
            cin >> x >> y >> w;
            --x; --y;
            dist[x][y] = dist[y][x] = w;
        }

        for(int k = 0; k <= n; ++k)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        vector<double> total_dist(n, 0.f);
        for(int i = 0; i < n; ++i)
        {
            double sum = 0.f;
            for(int j = 0; j < n; ++j)
            {
                sum += dist[i][j];
            }
            total_dist[i] = sum;
        }

        double ans;
        vector<vector<double>> initial;
        vector<vector<double>> transform_mat;
        for(int i = 0; i < n; ++i)
        {
            vector<double> row;
            double dist = total_dist[i];
            for(int j = 0; j < n; ++j)
            {
                row.push_back(i == j ? 0. : (1. / (n-1)));
            }
            row.push_back(total_dist[i] / (n-1));

            initial.push_back({0.});
            transform_mat.emplace_back(row);
        }
        initial.push_back({1.});
        transform_mat.push_back(vector<double>(n + 1, 0));
        transform_mat.back().back() = 1.;

        transform_mat = mat_pow(transform_mat, p);
        ans = mat_mul(transform_mat, initial)[0][0];

        cout << "Case #" << i + 1 << ": " << ans << '\n';
    }
    cout << flush;
}
