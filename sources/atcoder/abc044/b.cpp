#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    string s;
    cin >> s;

    char chs[26] = {};
    for(char ch : s) {
        chs[ch - 'a']++;
    }

    bool all = true;
    for(int i = 0; i < 26; ++i) {
        if(chs[i] % 2 != 0) { all = false; break; }
    }

    cout << (all ? "Yes" : "No") << endl;
}
