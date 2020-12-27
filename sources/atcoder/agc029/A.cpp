#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    using ll = long long;
    ll result = 0;
    int blacks = 0;
    int white = 0;
    for(int i = 0; i < str.size(); ++i) {
        char ch = str[i];
        if(ch == 'B') blacks++;
        else {
            result += blacks;
            swap(str[i], str[white]);
            white++;
        }
    }
    cout << result << endl;
}
