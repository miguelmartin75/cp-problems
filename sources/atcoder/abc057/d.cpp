#include <iostream>
#include <cmath>
#include <iomanip>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
    // x_i -> counts
    map<long long, int> counts;

    int n, a, b;
    cin >> n >> a >> b;

    for (int i = 0; i < n; ++i)
    {
        long long x;
        cin >> x;
        counts[x]++;
    }

    int num_ways = 0;
    double sum = 0;
    for(int k = a; k <= b; ++k)
    {
        int curr_ways = 0;
        double curr_sum = 0;

        bool picked = false;
        int amount_left = k;
        for(auto it = counts.rbegin(); it != counts.rend(); ++it)
        {
            int take = min(it->second, amount_left);
            curr_sum += take * it->first;

            if(take >= amount_left)
            {
                curr_ways = it->second - take + 1;
                if(!picked && k != 1) {
                    double temp = 1;
                    for(int i = 1; i <= k; ++i)
                    {
                        temp *= ((n + 1) - i) / (double)i;
                    }
                    curr_ways = (int)temp;
                }
                break;
            }

            amount_left -= take;
            picked = true;
        }

        curr_sum /= k;

        if(curr_sum > sum)
        {
            sum = curr_sum;
            num_ways = curr_ways;
        }
    }

    cout << fixed << setprecision(6) << sum << endl;
    cout << num_ways << endl;
}
