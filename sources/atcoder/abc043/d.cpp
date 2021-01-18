#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool unbalanced(string s) {
    sort(s.begin(), s.end());
    return s[0] == s[1] || s[1] == s[2];
}

int main(int argc, char *argv[]) {
    string s;
    cin >> s;

    if(s.size() == 2 && s[0] == s[1]) {
        cout << 1 << " " << 2 << endl;
        return 0;
    }

    for(int i = 0; i < s.size() - 2; ++i) {
        if(unbalanced(s.substr(i, 3))) {
            cout << i + 1 << " " << i + 3 << endl;
            return 0;
        }
    }

    cout << -1 << " " << -1 << endl;
}
