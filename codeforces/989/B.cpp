#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n, p;
    cin >> n >> p;

    string s;
    cin >> s;

    bool possible = false;
    for(int i = 0; i < s.size() - p && !possible; ++i)
    {
        if(s[i] != '.' && s[i + p] != '.')
        {
            if(s[i] != s[i + p])
            {
                possible = true;
            }
        }
        else
        {
            if(s[i] == '.' && s[i + p] == '.')
            {
                possible = true;
                s[i] = '0';
                s[i + p] = '1';
            }
            else if(s[i] == '.')
            {
                possible = true;
                s[i] = !(s[i + p] - '0') + '0';
            }
            else if(s[i + p] == '.')
            {
                possible = true;
                s[i + p] = !(s[i] - '0') + '0';
            }
        }
    }

    if(possible)
    {
        for(int i = 0; i < s.size(); ++i) if(s[i] == '.') s[i] = '0';
        cout << s << endl;
    }
    else
        cout << "No" << endl;
}
