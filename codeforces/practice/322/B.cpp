#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int a, b, c;
    cin >> a >> b >> c;

    int m = min(a, min(b, c));

    int ans = 0;
    for(int i = 0; i <= 2; ++i)
    {
        if(i > m) break;

        int A = a - i;
        int B = b - i;
        int C = c - i;

        ans = max(ans, i + A/3 + B/3 + C/3);
    }

    cout << ans << endl;
}
