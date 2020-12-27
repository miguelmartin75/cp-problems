#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    string s;
    cin >> s;

    for(int i = 1; i < s.size() - 1; ++i)
    {
        if(s[i - 1] == '.' || s[i] == '.' || s[i + 1] == '.') continue;

        if(s[i - 1] != s[i] && s[i] != s[i + 1] && s[i + 1] != s[i - 1])
        {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
}
