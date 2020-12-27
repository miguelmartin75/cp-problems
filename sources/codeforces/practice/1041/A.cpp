#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int& x : arr) cin >> x;

    sort(arr.begin(), arr.end());

    int missing = 0;
    for(int i = 1; i < arr.size(); ++i) {
        missing += arr[i] - arr[i - 1] - 1;
    }
    cout << missing << endl;
}
