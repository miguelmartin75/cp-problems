#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    bool seiv[1000*1000 * 2] = {};

    int n, m, k;
    cin >> n >> m >> k;

    //cout <<"n = " << n << ", m = " << m << endl;
    for(int i = 0; i <= m; ++i)
    {
        seiv[i*n] = true;
        int x = i*n;
        //cout << "i = " << i << endl;
        for(int j = 0; j < n; ++j)
        {
            x -= i;
            x += (m - i);
            if(x > 0)
                seiv[x] = true;
        }
    }

    //for(int i = 0; i < (m*n) + 1; ++i)
    //{
    //    cout << i << ": " << seiv[i] << endl;
    //}
    //cout << endl;

    cout << (seiv[k] ? "Yes" : "No") << endl;
}
