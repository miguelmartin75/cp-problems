#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    vector<string> S(3, "");
    vector<int> idx = {0, 0, 0};

    for(auto& s : S) cin >> s;

    const char* names[] = {"A", "B", "C"};

    int turn = 0;
    while(true) {

        if(idx[turn] >= S[turn].size()) {
            cout << names[turn] << endl;
            return 0;
        }

        char ch = S[turn][idx[turn]];
        idx[turn]++;
        turn = (ch - 'a');
    }

    cout << -1 << endl;
}
