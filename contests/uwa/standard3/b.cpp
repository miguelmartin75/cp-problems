#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int t;
    cin >> t;

    for(int i = 0; i < t; ++i)
    {
        int C, R;
        cin >> R >> C;

        double r = sqrt(static_cast<double>(R*R) - (C/2.0)*(C/2.0));
        cout << setprecision(6) << fixed;
        cout << (r * r * M_PI) << endl;
    }
}
