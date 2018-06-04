#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int& x : arr) cin >> x;

    sort(arr.begin(), arr.end());

    int amount = 0;
    for(int i = 2; i < arr.size(); i += 3)
    {
        if(5 - arr[i] < k) break;
        ++amount;
    }

    cout << amount << endl;
}
