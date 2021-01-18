#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    string s;
    cin >> s;

    string result;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] != 'B') result += s[i];
        else {
            if(!result.empty()) result.pop_back();
        }
    }

    cout << result << endl;
}
