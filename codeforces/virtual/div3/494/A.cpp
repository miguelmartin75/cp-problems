#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int arr[101] = {};
    int m = 1;
    for(int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        arr[x]++;

        m = max(arr[x], m);
    }

    cout << m << endl;
}
