#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    string s;
    getline(cin, s);

    int i = s.size() - 1;
    while(!(tolower(s[i]) >= 'a' && tolower(s[i]) <= 'z')) { --i; }

    char ch = tolower(s[i]);
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y')
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
