#include <bits/stdc++.h>
using namespace std;

vector<int> get_primes(int n) {
    vector<int> p(n + 1, 1);
    p[0] = p[1] = 0;

    for(int i = 2; i*i <= n; ++i) {
        if(!p[i]) continue;
        for(int j = i*i; j <= n; j += i) {
            p[j] = 0;
        }
    }

    vector<int> result;
    for(int i = 2; i <= n; ++i) {
        if(p[i]) result.push_back(i);
    }
    return result;
}

int main(int argc, char *argv[]) {
    auto primes = get_primes(200);
    set<int> semi;
    for(int x : primes) {
        for(int y : primes) {
            if(x == y) continue;
            semi.insert(x*y);
        }
    }

    int t;
    cin >> t;

    for(int i = 0; i < t; ++i) {
        int n; 
        cin >> n;

        bool ans = false;
        for(int x : semi) {
            if(semi.count(n - x) > 0) {
                ans = true;
                break;
            }
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }
}
