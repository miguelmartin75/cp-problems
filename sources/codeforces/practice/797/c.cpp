#include <bits/stdc++.h>
using namespace std;

int counts[26] = {};
char get_min()
{
    for(int i = 0; i < 26; ++i)
    {
        if(counts[i] > 0) return i + 'a';
    }
    return 'z';
}

int main(int argc, char *argv[])
{
    string s;
    cin >> s;

    for(char ch : s) counts[ch - 'a']++;

    stack<char> t;

    int i = 0;
    while(i < s.size()) {
        while(t.empty() || t.top() > get_min()) {
            t.push(s[i]);
            counts[s[i] - 'a']--;
            ++i;
        }

        while(!t.empty() && t.top() <= get_min()) {
            cout << t.top();
            t.pop();
        }
    }

    while(!t.empty()) {
        cout << t.top(); t.pop();
    }
}
