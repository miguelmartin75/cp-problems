#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int a, b, x;
    cin >> a >> b >> x;

    char small = a < b ? '0' : '1';
    char big = small == '0' ? '1' : '0';
    if(a < b) swap(a, b);

    bool add = false;
    if(2*b != x && x % 2 == 0)
    {
        --x;
        --b;
        add = true;
    }

    string s;
    for(int i = 0; i < b - x/2; ++i)
    {
        s += small;
    }

    for(int i = 0; i < x/2; ++i)
    {
        s += big;
        s += small;
    }

    for(int i = 0; i < a - x/2; ++i)
    {
        s += big;
    }

    if(add) s += small;

    cout << s << endl;
}
