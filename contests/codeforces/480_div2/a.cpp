#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    string s;
    cin >> s;

    int p = 0;
    int l = 0;
    for(char ch : s)
    {
        if(ch == '-') ++l;
        else ++p;
    }

    if(p <= 1 || l == 0) cout << "YES" << endl;
    else if(p <= l && l % p == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}
