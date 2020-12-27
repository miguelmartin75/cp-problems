#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int q;
    cin.tie(0);
    cin.sync_with_stdio(false);
    cin >> q;

    for(int i = 0; i < q; ++i)
    {
        int n;
        cin >> n;

        int res = 0;
        int x = 1;
        for(; x * x <= n; ++x)
        {
            int y = n / x;
            if(x * y == n)
            {
                res += x == y ? 1 : 2;
            }
        }
        cout << res << '\n';
    }

    cout << flush;
}
