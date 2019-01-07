#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using point = pair<ll, ll>;

ll x(const point& p) { return p.second; }
ll y(const point& p) { return p.first; }

ll A(const point& s, const point& p) { return -(y(s) - y(p)); }
ll B(const point& s, const point& p) { return x(s) - x(p); }
ll C(const point& s, const point& p) { return -B(s, p)*y(p) - A(s, p)*x(p); }

bool is_colinear(const point& p1, const point& p2, const point& p3)
{
    const ll a = A(p1, p2); // Ax
    const ll b = B(p1, p2); // By
    const ll c = C(p1, p2);

    return a*x(p3) + b*y(p3) + c == 0ll;
}

int main(int argc, char *argv[])
{
    ll n;
    cin >> n;

    vector<point> points(n);
    for(auto& p : points) cin >> p.second >> p.first;

    vector<int> indices;
    for(int i = 0; i < points.size(); ++i) indices.push_back(i);

    sort(indices.begin(), indices.end(), [&](int p1, int p2) {
        return points[p1] < points[p2];
    });

    int i = 2;
    while(is_colinear(points[indices[0]], points[indices[1]], points[indices[i]])) { ++i; }

    cout << indices[0] + 1 << ' ';
    cout << indices[1] + 1 << ' ';
    cout << indices[i] + 1 << endl;
}
