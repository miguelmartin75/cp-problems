#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<bool> poss(n, true);
    for(int i = 0; i < m; ++i)
    {
        int x; cin >> x;
        poss[x] = false;
    }

    vector<int> cost(k, 0);
    for(int& x : cost) cin >> x;

    int longest_seq = 0;
    int seq = 0;
    for(int i = 0; i < poss.size(); ++i)
    {
        if(poss[i]) seq = 0;
        else seq++;

        longest_seq = max(seq, longest_seq);
    }

    if(longest_seq + 1 > k || !poss[0])
    {
        cout << -1 << endl;
    }
    else
    {
        vector<int> closest0(n);
        closest0[0] = 0;
        for(int i = 1; i < n; ++i)
        {
            if(!poss[i]) closest0[i] = closest0[i - 1];
            else closest0[i] = i;
        }

        long long min_cost = numeric_limits<long long>::max();
        for(int l = longest_seq + 1; l <= k; ++l)
        {
            long long amount = 0;

            int i = 0;
            while(i < n)
            {
                i = closest0[i];
                amount++;
                i += l;
            }

            min_cost = min(min_cost, amount * cost[l - 1]);
        }

        cout << min_cost << endl;
    }
}
