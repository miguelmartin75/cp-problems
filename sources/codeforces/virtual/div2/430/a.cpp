#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int l, r, x, y, k;
    cin >> l >> r >> x >> y >> k;

    bool found = false;
    for(int a = l; a <= r; ++a)
    {
        if(a % k != 0)
        {
            continue;
        }
        int b = a / k;
        if(b >= x && b <= y)
        {
            found = true;
            break;
        }
    }

    cout << (found ? "YES" : "NO") << endl;
}
