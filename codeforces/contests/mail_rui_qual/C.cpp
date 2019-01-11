#include <bits/stdc++.h>
using namespace std;

string c;

int f(vector<int>& r, int i, int k) {
    if(k <= 0) return 0;

    int val = r[i];
    r[i] = 0; // mark visited

    cout << "i = " << i << endl;
    int ans = INT_MAX;
    for(int u : {i - 1, i + 1}) {
        if(u < 0 || u >= r.size()) continue;
        if(c[u] == c[i]) continue;

        cout << "r[u] = " << r[u] << "(" << val << ")" << endl;
        if(val >= r[u]) continue;

        int p = f(r, u, k - val);
        if(p == -1) continue;

        ans = min(ans, p);
    }

    return ans == INT_MAX ? -1 : ans + 1;
}

int main(int argc, char *argv[]) {
    int n, s, k;
    cin >> n >> s >> k;

    --s;

    vector<int> r(n);
    for(int& x : r) cin >> x;

    cin >> c;

    int min_val = 51;
    for(int i = s; i <= s; ++i) {
        vector<int> temp = r;
        int path = f(temp, i, k - r[i]);
        cout << "path = " << path << ", for i = " << i << endl;
        if(path == -1) continue;

        path += (s - 1) - i + 1;
        min_val = min(min_val, path);
    }

    if(min_val == 51) min_val = -1;
    cout << min_val << endl;
}
