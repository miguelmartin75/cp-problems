#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    bool seats[100000] = {};
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int l, r;
        cin >> l >> r;
        l -= 1;
        r -= 1;
        for(int j = l; j <= r; ++j) seats[j] = true;
    }

    cout << accumulate(begin(seats), end(seats), 0) << endl;
}
