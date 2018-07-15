#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    vector<int> a(n);
    for(int& x : a) cin >> x;

    int res = 0;
    int amount = 1;
    for(int i = 1; i < a.size(); ++i) {
        if(a[i - 1] == a[i]) amount++;
        else
        {
            res += amount / 2;
            amount = 1;
        }
    }

    res += amount / 2;

    cout << res << endl;
}
