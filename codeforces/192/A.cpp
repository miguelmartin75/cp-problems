#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    set<int> tri;
    for(int k = 1; ; ++k)
    {
        int num = (k*(k+1))/2;
        if(num > n) break;

        tri.emplace(num);
    }

    for(int a : tri)
    {
        // a + b = n
        // b = n - a
        int b = n - a;
        if(tri.count(b))
        {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
}
