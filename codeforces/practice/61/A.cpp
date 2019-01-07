#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    string s1, s2;
    cin >> s1 >> s2;

    for(int i = 0; i < s1.size(); ++i)
    {
        int x = s1[i] == '1';
        int y = s2[i] == '1';

        cout << (x ^ y);
    }
    cout << endl;
}
