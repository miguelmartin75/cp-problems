#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int counts[26] = {};

    string line;
    for(int i = 0; i < 2; ++i)
    {
        getline(cin, line);
        for(char ch : line) counts[ch - 'A']++;
    }

    getline(cin, line);
    for(char ch : line) counts[ch - 'A']--;

    for(int x : counts)
    {
        if(x != 0)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}
