#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;

        int x;
        for(int i = 0; i < n + 1; ++i)
        {
            cin >> x;
        }

        cout << "Case #" << i + 1 << ": ";
        if(n % 2 != 0)
        {
            cout << setprecision(1);
            cout << fixed;
            cout << 1 << endl << 0.0 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
}
