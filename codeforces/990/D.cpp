#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n, a, b;
    cin >> n >> a >> b;

    int A = max(a, b);
    int B = min(a, b);

    bool possible = false;
    if(n == 2 || n == 3)
    {
        possible = B == 1 && A > 1 && A <= n;
    }
    else
    {
        possible = B == 1 && A >= 1 && A <= n;
    }

    if(possible)
    {
        cout << "YES" << endl;
        vector<vector<bool>> mat(n, vector<bool>(n, A != a));

        for(int i = 0; i < n; ++i)
            mat[i][i] = false;

        if(A == 1)
        {
            for(int i = 1; i < n; ++i)
            {
                mat[i][i - 1] = mat[i - 1][i] = true;
            }
        }
        else
        {
            vector<vector<int>> components(A);
            for(int i = 0; i < n; ++i)
            {
                int x = n / A;
                int index = min(A - 1, i / x);
                components[index].push_back(i);
            }

            for(auto& c : components)
            {
                for(int i = 0; i < c.size(); ++i)
                {
                    for(int j = i + 1; j < c.size(); ++j)
                    {
                        int u = c[i];
                        int v = c[j];
                        mat[u][v] = mat[v][u] = !mat[u][v];
                    }
                }
            }
        }

        for(auto& r : mat)
        {
            for(auto c : r)
            {
                cout << c;
            }
            cout << endl;
        }
    }
    else
    {
        cout << "NO" << endl;
    }
}
