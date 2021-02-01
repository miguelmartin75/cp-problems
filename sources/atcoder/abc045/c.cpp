#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    string s;
    cin >> s;

    long long total = 0;
    for(int b = 0; b < (1 << (s.size() - 1)); ++b) {
        long long curr = 0;
        for(int i = 0; i < s.size(); ++i) {
            curr *= 10;
            curr += (s[i] - '0');
            if(b & (1 << i)) {
                total += curr;
                curr = 0;
            }
        }
        total += curr;
    }
    cout << total << endl;
}
