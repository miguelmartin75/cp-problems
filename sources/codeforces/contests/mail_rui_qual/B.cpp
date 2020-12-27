#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n;
    cin >> n;

    vector<int> a(n);
    for(auto& x : a) cin >> x;

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        int s = 0;
        for(int j = i; j >= 0; --j) {
            s += a[j];
            int len = i - j + 1;
            if(s > 100*len)
                ans = max(ans, len);
        }
    }

    cout << ans << endl;
}
