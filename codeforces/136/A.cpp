#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    vector<int> res(n);
    for(int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        --x;
        res[x] = i + 1;
    }

    for(int x : res)
        cout << x << ' ';
    cout << '\n';
}
