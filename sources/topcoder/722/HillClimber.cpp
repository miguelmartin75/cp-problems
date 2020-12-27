#include <bits/stdc++.h>
using namespace std;

struct HillClimber
{
    int longest(vector<int> height)
    {
        int max_amount = 0;
        int amount = 0;
        for(int i = 1; i < height.size(); ++i)
        {
            if(height[i - 1] < height[i]) 
            {
                ++amount;
                max_amount = max(max_amount, amount);
            }
            else
            {
                amount = 0;
            }
        }
        return max_amount;
    }
};

#ifdef LOCAL
int main(int argc, char *argv[])
{
    HillClimber hill;
    cout << hill.longest({5, 2, 1, 2, 3}) << endl;
}
#endif
