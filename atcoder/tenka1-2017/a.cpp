#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    long long N;
    cin >> N;

    for(long long h = 1; h <= 3500; ++h)
    {
        for(long long n = 1; n <= 3500; ++n)
        {
            long long top = N*h*n;
            long long bottom = 4 * h * n - N * (n + h);

            if(bottom == 0) continue;

            long long w = top / bottom;
            if(w <= 0) continue;

            if(top % bottom == 0)
            {
                cout << h << ' ' << n << ' ' << w << endl;
                return 0;
            }
        }
    }
}
