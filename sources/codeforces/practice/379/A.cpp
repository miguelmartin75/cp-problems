#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int a, b;
    cin >> a >> b;

    int ans = 0; 
    int spare = 0;
    while(a > 0) 
    {
        ans += a;

        spare += a;
        a = spare / b;
        spare -= a * b;
    }

    cout << ans << endl;
}
