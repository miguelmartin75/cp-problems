#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> factors;
    factors.reserve(k);
    for(int i = 2; i * i <= n; ++i) {
        while(n % i == 0) {
            if((int)factors.size() == k) {
                factors.back() *= i;
            }
            else {
                factors.push_back(i);
            }
            n /= i;
        }
    }

    if(n > 1) {
        if((int)factors.size() == k) {
            factors.back() *= n;
        }
        else {
            factors.push_back(n);
        }
    }


    if((int)factors.size() == k)
        for(auto& x : factors) cout << x << ' ';
    else cout << -1;
}
