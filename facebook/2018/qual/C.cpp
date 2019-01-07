#include <bits/stdc++.h>
using namespace std;

bool original(string a, string b)
{
    int i = 0, j = 0;
    while(true)
    {
        if(i >= a.size()) return true;
        if(j >= b.size()) return false;

        if(a[i] == b[j]) { i++; j++; }
        else if(i == 0) { j++; }
        else i = 0;
    }
    return false;
}

void solve(string a)
{
    vector<int> kmp(a.size());
    kmp[0] = 0;

    int j = 0;
    for(int i = 1; i < a.size(); ++i)
    {
        while(j > 0 && a[i] != a[j]) j = kmp[j - 1];
        if(a[i] == a[j])
        {
            ++j;
        }

        kmp[i] = j;
    }

    int i = 0;
    while(i < a.size() && kmp[i] == 0) i++;

    j = i + 1;
    while(j < a.size() && kmp[j] != 0) j++;

    if(i < a.size() && j < a.size() && kmp[i] != 0 && kmp[j] == 0)
    {
        string pre = a.substr(0, i);
        string ans = pre + a;
        cout << ans;

#ifdef DEBUG
        bool x1 = original(a, ans);
        bool x2 = ans.find(a) != string::npos;
        if(x1 || (!x1 && !x2))
        {
            cerr << endl << "ERROR, produced:\n" << ans << "\nfor input\n" << a << endl;
            exit(1);
        }
#endif
    }
    else
    {
        cout << "Impossible";
    }
}

int main(int argc, char *argv[])
{
    int t;
    cin >> t;

    for(int i = 0; i < t; ++i)
    {
        string a;
        cin >> a;
        cout << "Case #" << i + 1 << ": ";
        solve(a);
        cout << '\n';
    }
}
