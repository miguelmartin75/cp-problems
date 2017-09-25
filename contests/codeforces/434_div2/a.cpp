#include <bits/stdc++.h>
using namespace std;

int count_zeros(long long x)
{
    int c = 0;
    while(x > 0)
    {
        long long d = x % 10;
        if(d != 0) break;
        ++c;
        x /= 10;
    }
    return c;
}

int main(int argc, char *argv[])
{
    long long n;
    int k;
    cin >> n >> k;

    int m = 1;
    while(k-- > 0) m *= 10;

    for(int i = 1; ; ++i)
    {
        int x = i * m;
        if(x % n == 0)
        {
            cout << x << endl;
            break;
        }
    }
}
