#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n, l;
    cin >> n >> l;

    vector<string> S(n, "");
    for(auto& x : S) cin >> x;

    sort(S.begin(), S.end());

    for(auto& x : S) cout << x;
    cout << endl;
}
