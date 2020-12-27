#include <bits/stdc++.h>
using namespace std;

bool isPalin(string s) {
    return s == string{s.rbegin(), s.rend()};
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    sort(s.begin(), s.end());
    cout << s << '\n';
    
    //int count = 0;
    //for(int i = 0; i < s.size(); ++i) {
    //    for(int j = 1; j <= s.size() - i; ++j) {
    //        string substr = s.substr(i, j);
    //        if(isPalin(substr)) { ++count; }
    //    }
    //}
    //cout << count << endl;
}
