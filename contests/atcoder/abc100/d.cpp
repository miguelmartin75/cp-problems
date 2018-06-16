#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(int argc, char *argv[])
{
    int N, M;
    cin >> N >> M;

    vector<ll> a1(N);
    vector<ll> a2(N);
    vector<ll> a3(N);

    for(int i = 0; i < N; ++i) cin >> a1[i] >> a2[i] >> a3[i];

    vector<tuple<ll, ll, ll>> prev(M + 1, {0, 0, 0});
    vector<tuple<ll, ll, ll>> curr = prev;
    for(int i = 0; i < N; ++i)
    {
        for(int m = 1; m <= M; ++m)
        {
            const ll p1 = get<0>(prev[m]);
            const ll p2 = get<1>(prev[m]);
            const ll p3 = get<2>(prev[m]);

            const ll v1 = get<0>(prev[m - 1]) + a1[i];
            const ll v2 = get<1>(prev[m - 1]) + a2[i]; 
            const ll v3 = get<2>(prev[m - 1]) + a3[i];

            const ll v = abs(v1) + abs(v2) + abs(v3);
            const ll p = abs(p1) + abs(p2) + abs(p3);


            if(p <= v)
            {
                curr[m] = make_tuple(v1, v2, v3);
            }
            else
            {
                curr[m] = make_tuple(p1, p2, p3);
            }
        }

        swap(prev, curr);
    }


    ll v1 = abs(get<0>(prev.back()));
    ll v2 = abs(get<1>(prev.back()));
    ll v3 = abs(get<2>(prev.back()));
    ll m = v1 + v2 + v3;
    cout << m << endl;
}
