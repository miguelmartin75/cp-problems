#include <bits/stdc++.h>
using namespace std;

bool is_vowel(char ch)
{
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int main(int argc, char *argv[])
{
    string s;
    cin >> s;

    int c = 0;
    set<char> set;
    for(int i = 0; i < s.size(); ++i)
    {
        char ch = s[i];
        if(is_vowel(ch))
        {
            set.clear();
            cout << ch;
        }
        else
        {
            set.insert(ch);
            ++c;
            if(set.size() >= 2 && c >= 3)
            {
                cout << ' ';
                set.clear();
                set.insert(ch);
            }

            cout << ch;
        }
    }
    cout << endl;
}
