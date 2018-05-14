#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    string s;
    cin >> s;

    vector<int> sum(s.size(), 0);
    for(int i = 1; i < s.size(); ++i)
        sum[i] = sum[i - 1] + (s[i - 1] == s[i]);
    
    int m;
    cin >> m;

    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;

        --a; --b;

        cout << sum[b] - sum[a] << '\n';
    }
}
