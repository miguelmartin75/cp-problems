#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int a, m;
    cin >> a >> m;

    set<int> seen;
    seen.emplace(a);
    while(true)
    {
        a += a % m;
        a = a % m;
        if(seen.count(a))
        {
            cout << "No" << endl;
            break;
        }
        seen.emplace(a);
        if(a == 0)
        {
            cout << "Yes" << endl;
            break;
        }
    }
}
