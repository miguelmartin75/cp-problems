#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    int l = 0;
    int r = 0;
    int num_swap = 0;
    for(int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;

        if(x % 2 != y % 2)
        {
            num_swap++;
        }

        l += (x % 2) != 0;
        r += (y % 2) != 0;
    }

    bool b1 = (l % 2) == 0;
    bool b2 = (r % 2) == 0;

    if(b1 && b2) cout << 0;
    else if(b1 || b2) cout << -1;
    else cout << ((num_swap >= 1) ? 1 : -1);
    cout << endl;
}
