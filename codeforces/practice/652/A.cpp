#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int h1, h2;
    int a, b;
    cin >> h1 >> h2 >> a >> b;

    int k = 0;
    if(h1 + 8*a >= h2)
    {
        cout << k << endl;
        return 0;
    }

    int curr = h1 + 8*a - 2*b;
    int prev = curr;
    k++;
    while(true)
    {
        curr += -10*b + 12*a;
        if(curr >= h2)
        {
            cout << k << endl;
            return 0;
        }
        else if(curr == prev || curr <= h1)
        {
            cout << -1 << endl;
            return 0;
        }

        k++;
        prev = curr;
        curr -= 2*b;
    }

}
