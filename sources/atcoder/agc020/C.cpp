#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    vector<int> A(n);
    int s = 0;
    for(int& x : A) { cin >> x; s += x; }

    bitset<2000*2000 + 1> c;

    for(int i = 0; i < n; ++i)
    {
        c |= (c << A[i]);
        c[A[i]] = true;
    }

    for(int i = (s+1)/2; i < c.size(); ++i)
    {
        if(c[i])
        {
            cout << i << endl;
            return 0;
        }
    }
}
