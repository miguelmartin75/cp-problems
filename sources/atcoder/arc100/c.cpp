#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 1; i <= n; ++i)
    {
        int x; cin >> x;
        x -= i;
        a[i - 1] = x;
    }

    nth_element(a.begin(), a.begin() + a.size() / 2, a.end());
    int median = a[a.size()/2];
    long long s = 0;
    for(int x : a)
        s += abs(x - median);
    cout << s << endl;
}
