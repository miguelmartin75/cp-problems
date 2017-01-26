#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int m;
        cin >> m;
        int res = INT_MIN;
        for (int i = 0; i < m; ++i)
        {
            int x;
            cin >> x;
            res = max(x, res);
        }
        cout << "Case " << i + 1 << ": " << res << endl;
    }
}
