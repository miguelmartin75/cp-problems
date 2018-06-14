#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    string inp;
    cin >> inp;

    int m = INT_MAX;
    for(int x = 0; x <= 1; ++x)
    {
        string s = inp;

        char ch = x ? 'r' : 'b';
        string a;
        for(int i = 0; i < n; ++i)
        {
            a += ch;
            ch = ch == 'r' ? 'b' : 'r';
        }


        int r = n - 1;
        int b = n - 1;

        int ops = 0;
        for(int i = 0; i < n; ++i)
        {
            if(s[i] != a[i])
            {
                while(r >= 0 && (s[r] == 'b' || a[r] == s[r])) { --r; }
                while(b >= 0 && (s[b] == 'r' || a[b] == s[b])) { --b; }

                ops++;

                int& idx = s[i] == 'r' ? b : r;

                if(idx >= 0) 
                {
                    swap(s[i], s[idx]);
                    --idx;
                }
                else
                {
                    s[i] = s[i] == 'r' ? 'b' : 'r';
                }
            }
        }

        m = min(ops, m);
    }

    cout << m << endl;
}
