#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    string s; cin >> s;

    int m = 0;
    for(int i = 1; i < s.size() - 1; ++i) {
        string a = s.substr(0, i + 1);
        string b = s.substr(i + 1);

        set<char> aS{a.begin(), a.end()};
        set<char> bS{b.begin(), b.end()};
        int x = 0;
        for(char ch : bS) {
            if(aS.count(ch) > 0) x++;
        }
        m = max(m, x);
    }
    cout << m << endl;
}
