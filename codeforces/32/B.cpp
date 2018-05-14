#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    string s;
    cin >> s;

    for(int i = 0; i < s.size(); )
    {
        if(s[i] == '.')
        {
            cout << 0;
            i++;
        }
        else if(s[i] == '-' && s[i + 1] == '.')
        {
            cout << 1;
            i += 2;
        }
        else
        {
            cout << 2;
            i += 2;
        }
    }
    cout << endl;
}
