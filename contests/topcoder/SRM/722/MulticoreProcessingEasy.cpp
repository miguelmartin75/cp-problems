#include <bits/stdc++.h>
using namespace std;

int myceil(int x, int y)
{
    return x / y + (x % y == 0 ? 0 : 1);
}

struct MulticoreProcessingEasy
{
    int fastestTime(int jobLength, int corePenalty, vector<int> speed, vector<int> cores)
    {
        int fastest = INT_MAX;
        for(int i = 0; i < speed.size(); ++i)
        {
            int time = myceil(jobLength, (speed[i] * cores[i]));
            int penalty = corePenalty * (cores[i] - 1);
            fastest = min(fastest, time + penalty);
        }
        return fastest;
    }
};

#ifdef LOCAL
int main(int argc, char *argv[])
{
    MulticoreProcessingEasy mp;
    //cout << mp.fastestTime(1000, 0, {10}, {3}) << endl;
    cout << mp.fastestTime(1000, 10000, {10}, {3}) << endl;
}
#endif
