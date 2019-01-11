#include <bits/stdc++.h>
using namespace std;

using ll = long long;
struct TaroCoins 
{
    ll getNumber(ll n)
    {
        if(n == 0) return 0;

        int g = 0;
        vector<int> gaps;
        for(int i = 0; i < 64; ++i)
        {
            if((1ll << i) & n)
            {
                gaps.push_back(g + 1);
                g = 0;
            }
            else
            {
                g++;
            }
        }

        ll w1 = 1;
        ll w2 = 1;
        for(int i = 0; i < gaps.size(); ++i)
        {
            ll z = gaps[i];
            ll newW = z*w2 + (z + 1)*(w1 - w2);
            w2 = w1;
            w1 = newW;
        }

        return w1;
    }
};

#ifdef LOCAL
int main(int argc, char *argv[])
{
    TaroCoins c;

    //for(int x : {2, 10, 74})
    //for(int x : {1, 6, 2, 74, 256, 10, 18, 20})
    for(int x : {1, 6, 47, 256, 8489289, 1000000000})
    {
        cout << x << " = " << c.getNumber(x) << endl;
    }
}
#endif
