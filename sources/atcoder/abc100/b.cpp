#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n, b;
    cin >> b >> n;

    int mult = 1;
    if(b > 0) mult = b == 1 ? 100 : 10000;

    if(n <= 99)
    {
        cout << n * mult << endl;
    }
    else
    {
        cout << 101 * mult << endl;
    }
}
