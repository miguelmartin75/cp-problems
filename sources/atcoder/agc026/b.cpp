#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(int argc, char *argv[])
{
    int t;
    cin >> t;

    for(int i = 0; i < t; ++i)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        //cout << "a = " << a << ", b = " << b << ", c = " << c << ", d = " << d << endl;

        map<ll, bool> seen;
        ll supply = a;
        while(supply >= b)
        {
            // DAY
            //cout << "D = " << supply << endl;
            ll amount = supply <= c ? supply / b : (supply - c) / b;
            supply -= amount * b;
            if(supply >= b) supply -= b;

            //cout << "N = " << supply << endl;

            if(seen[supply])
            {
                supply = b;
                break;
            }

            seen[supply] = true;

            // NIGHT
            if(supply <= c)
                supply += d;
        }

        if(supply >= b) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
