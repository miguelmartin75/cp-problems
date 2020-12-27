#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    
    double s = 0;
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        s += x;
    }

    s /= n;

    cout << fixed;
    cout << setprecision(5);
    cout << s << endl;
}
