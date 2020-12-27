#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int t;
    cin >> t;

    for(int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int& x : a) cin >> x;

        vector<int> b(n);
        for(int i = 0; i < n; ++i) { cin >> b[i]; b[i] -= a[i]; }

        int j = 0;

        while(j < n - 2) {
            while(j < n - 2 && b[j] == 0) ++j;
            if(j >= n - 2) break;
            if(b[j] < 0) break;

            b[j + 2] -= 3*b[j];
            b[j + 1] -= 2*b[j];
            b[j] = 0;
        }


        bool valid = true;
        for(int x : b) {
            if(x != 0) { valid = false; break; }
        }
        cout << (valid ? "TAK" : "NIE") << endl;
    }
}
