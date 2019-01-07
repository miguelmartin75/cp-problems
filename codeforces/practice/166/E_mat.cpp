#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll M = 1e9 + 7;

ll add(ll x, ll y)
{
    return ((x % M) + (y % M)) % M;
}

ll mult(ll x, ll y)
{
    return ((x % M) * (y % M)) % M;
}

using Row = vector<ll>;
using Mat = vector<Row>;

Mat mult(const Mat& m1, const Mat& m2)
{
    Mat result;
    for(int i = 0; i < m1.size(); ++i)
    {
        result.emplace_back(); // add a row

        for(int j = 0; j < m2[0].size(); ++j) // every col
        {
            int v = 0;
            for(int k = 0; k < m2.size(); ++k)
            {
                v = add(v, mult(m1[i][k], m2[k][j]));
            }

            result.back().emplace_back(v);
        }
    }
    return result;
}

// assume p >= 1
Mat pow(const Mat& m, int p)
{
    if(p == 0)
    {
        Mat res(m.size(), Row(m.size(), 0));
        for(int i = 0; i < m.size(); ++i)
            res[i][i] = 1;
        return res;
    }

    if(p % 2 == 0)
    {
        auto temp = pow(m, p/2);
        return mult(temp, temp);
    }

    return mult(pow(m, p - 1), m);
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    Mat transform = {
        { 2, 1 },
        { 3, 0 }
    };

    Mat initial = { 
        { 1 },
        { 0 } 
    };

    transform = pow(transform, n - 1);

    auto result = mult(transform, initial);

    cout << result[1][0] << '\n';
}
