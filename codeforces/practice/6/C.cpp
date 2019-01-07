#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int& x : arr) cin >> x;

    int a = 0;
    int b = arr.size() - 1;

    int num_a = 0;
    int num_b = 0;
    while(b - a > 1)
    {
        int m = min(arr[a], arr[b]);

        arr[a] -= m;
        arr[b] -= m;

        if(arr[a] == 0) { ++a; ++num_a; }
        if(arr[b] == 0) { --b; ++num_b; }
    }

    if(a == b)
    {
        num_a++;
    }
    else
    {
        num_a++;
        num_b++;
    }

    cout << num_a << ' ' << num_b << endl;
}
