#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    string s;
    cin >> s;

    int num_lower = 0;
    for(char ch : s) if(islower(ch)) ++num_lower;

    for(char ch : s)
    {
        if(num_lower >= s.size() - num_lower)
        {
            cout << (char)tolower(ch);
        }
        else
        {
            cout << (char)toupper(ch);
        }
    }
    cout << endl;
}
