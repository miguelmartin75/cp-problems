#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    long long n, r, avg;
    cin >> n >> r >> avg;

    avg *= n;

    vector<pair<int, int>> ess(n);
    long long score = 0;
    for(auto& x : ess)
    {
        cin >> x.first >> x.second;
        score += x.first;
    }

    sort(ess.begin(), ess.end(), [](auto& x1, auto& x2) { return x1.second < x2.second; });

    int i = 0;
    long long num = 0;
    while(true)
    {
        if(score >= avg) break;
        while(ess[i].first >= r) i++;

        long long amount = r - ess[i].first;
        amount = min(avg - score, amount);

        score += amount;
        ess[i].first += amount;

        num += amount * ess[i].second;
    }

    cout << num << endl;
}
