#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int i = 0; i < t; ++i) {
        int n, k; 
        cin >> n >> k;
        
        vector<int> a(n);
        for(int& x : a) cin >> x;

        sort(a.rbegin(), a.rend());

        int j = k - 1;
        while(j + 1 < n && a[j + 1] == a[j]) ++j;

        cout << j + 1 << '\n';
    }
}
