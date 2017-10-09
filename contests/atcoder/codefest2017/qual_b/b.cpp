#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    map<int, int> counts;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        counts[x]++;
    }

    bool valid = true;
    int m;
    cin >> m;
    for(int i = 0; i < m; ++i)
    {
        int x;
        cin >> x;
        if(counts[x] == 0) { valid = false; break; }
        counts[x]--;
    }
    
    cout << (valid ? "YES" : "NO") << endl;
}
