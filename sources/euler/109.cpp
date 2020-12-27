#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);

    for(int i = 1; i <= 21; ++i)
    {
        if(i == 21) i = 25;
        if(2*i >= dp.size()) continue;
        dp[2*i]++;
    }

    for(int i = 0; i < dp.size(); ++i)
    {
        dp[i] += dp[i - 1];
    }

    vector<pair<int, int>> pos;
    for(int i = 0; i <= 21; ++i)
    {
        int end = 3;
        if(i == 0) end = 1;
        if(i == 21) { i = 25; end = 2; }
        for(int x = 1; x <= end; ++x)
        {
            pos.emplace_back(i, x);
        }
    }

    int num = 0;
    for(int i = 0; i < pos.size(); ++i)
    {
        const int A = pos[i].first * pos[i].second;
        for(int j = i; j < pos.size(); ++j)
        {
            const int B = pos[j].first * pos[j].second;

            const int score = A + B;
            if(n - score - 1 < 0) continue;
            num += dp[n - score - 1];
        }
    }

    cout << num << endl;
}
