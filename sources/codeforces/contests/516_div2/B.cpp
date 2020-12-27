#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        bitset<32> a(x);

        int c = a.count();
        c = (1 << c);
        cout << c << '\n';
    }
}
