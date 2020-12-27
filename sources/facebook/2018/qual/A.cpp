#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int i = 0; i < t; ++i)
    {
        ll n, k, v;
        cin >> n >> k >> v;

        vector<string> A(n);
        for(auto& x : A) cin >> x;

        vector<int> ans;
        int start = ((v-1)%n * k%n)%n;
        for(int j = 0; j < k; ++j)
        {
            ans.push_back((start + j)%n);
        }

        sort(ans.begin(), ans.end());

        cout << "Case #" << i + 1 << ": ";
        for(int x : ans)
        {
            cout << A[x] << ' ';
        }
        cout << '\n';
    }
}
