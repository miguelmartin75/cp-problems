#include <bits/stdc++.h>
using namespace std;

bool has_nine(int x)
{
    while(x > 0)
    {
        if(x % 10 == 9) return true;
        x /= 10;
    }
    return false;
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    cout << (has_nine(n) ? "Yes" : "No") << endl;
}
