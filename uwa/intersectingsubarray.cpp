#include <iostream>
#include <vector>
#include <limits>
#include <random>
#include <queue>
using namespace std;

using ll = long long;

// p = lg2(x) 
// 2^p > x
int lg2(int x) {
    int p = 0;
    while(x > 0) { 
        p++; x /= 2; 
    }
    return p;
}

template <class F>
vector<vector<ll>> create_rmq(vector<ll>& input, F combine) {
    const int N = input.size();

    vector<vector<ll>> rmq;
    rmq.emplace_back(input); // i^0

    const int max_p = lg2(N);
    for(int p = 1; p < max_p; ++p) {
        const int offset = 1 << (p - 1);
        const int num_elements = N - offset;

        rmq.emplace_back();
        rmq.back().resize(num_elements);
        for(int i = 0; i < num_elements; ++i) {
            rmq[p][i] = combine(rmq[p - 1][i], rmq[p - 1][i + offset]);
        }
    }
    return rmq;
}

template <class F>
ll query(vector<vector<ll>>& rmq, int lo, int hi, F combine) {
    const int p = lg2(hi - lo + 1) - 1;
    return combine(rmq[p][lo], rmq[p][hi - (1 << p) + 1]);
}

ll solve(vector<ll>& contains, int lo, int hi) {
    ll result = contains[lo];
    for(int i = lo; i <= hi; ++i) {
        result = max(result, contains[i]);
    }
    return result;
}

vector<ll> maxContains(vector<ll>& a) {
    const int n = a.size();

    vector<ll> beg(n);
    vector<ll> end(n);

    for(int i = 0; i < n; ++i) {
        int e = n - 1 - i;

        beg[e] = a[e];
        end[i] = a[i];

        if(e + 1 < n) {
            beg[e] = max(beg[e], beg[e + 1] + a[e]);
        }
        if(i - 1 >= 0) {
            end[i] = max(end[i], end[i - 1] + a[i]);
        }
    }

    vector<ll> res(n);

    for(int i = 0; i < n; ++i) {
        res[i] = max(end[i], beg[i]);
        if(i + 1 < n)
            res[i] = max(end[i] + beg[i + 1], res[i]);
        if(i - 1 >= 0)
            res[i] = max(end[i - 1] + beg[i], res[i]);
    }

    return res;
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<ll> a(n);
    for(auto& x : a) cin >> x;

    auto contains = maxContains(a);

    auto combine = [](ll x, ll y) { return max(x, y); };
    auto rmq = create_rmq(contains, combine);
    
    for(int i = 0; i < q; ++i) {
        int lo, hi;
        cin >> lo >> hi;
        
        if(hi < lo) swap(lo, hi);

        --lo; --hi;

        ll ans = query(rmq, lo, hi, combine);
        cout << ans << '\n';
    }
}
