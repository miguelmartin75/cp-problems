#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int& x : a) cin >> x;

    int m;
    cin >> m;

    vector<int> b(m);
    for(int& x : b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0;
    int j = 0;
    
    int x = 2*n, y = 2*m;
    int max = x - y;
    while(i != n || j != m)
    {
        int A = 2*i;
        if(i != n) A += 3*(n - i);

        int B = 2*j;
        if(j != m) B += 3*(m - j);

        int diff = A - B;
        if(diff >= max)
        {
            if(diff > max || x < A)
            {
                x = A;
                y = B;
            }
            max = diff;
        }

        if(i == n) ++j;
        else if(j == m) ++i;
        else
        {
            if(a[i] < b[j]) ++i;
            else if(a[i] > b[j]) ++j;
            else
            {
                ++i;
                ++j;
            }
        }
    }

    cout << x << ":" << y << endl;
}
