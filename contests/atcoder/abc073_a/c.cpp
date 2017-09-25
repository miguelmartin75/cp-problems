#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    unordered_map<int, bool> m;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        m[x] = !m[x];
    }
    cout << accumulate(m.begin(), m.end(), 0, [](auto& x, auto& y) { return x + y.second; }) << endl;
}
