#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    map<int, int> counts;
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        counts[x]++;
    }

    bool valid = false;
    if(counts.size() == 2) 
    {
        auto x = counts.begin();
        auto y = (++counts.begin());
        if(x->second == y->second)
        {
            cout << "YES\n";
            cout << x->first << ' ' << y->first << endl;
            valid = true;
        }
    }
    if(!valid)
    {
        cout << "NO" << endl;
    }
}
