#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int& x : a) cin >> x;

    for(int i = 1; i < a.size(); ++i)
    {
        a[i] += a[i - 1];
    }
    
    double m = -1;
    for(int i = k; i <= n; ++i)
    {
        for(int j = 0; j + i - 1 < n; ++j)
        {
            int e = j + i - 1;
            int s = a[e];
            if(j - 1 >= 0)
                s -= a[j - 1];
            double avg = s / (double)i;
            m = max(avg, m);
        }
    }

    cout << setprecision(7);
    cout << fixed;
    cout << m << endl;
}
