#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    string s; cin >> s;

    vector<int> A(n, 0);
    vector<int> B(n, 0);

    for(int i = 1; i < n; ++i) {
        A[i] = A[i - 1] + (s[i - 1] == 'W');
    }

    for(int i = n - 2; i >= 0; --i) {
        B[i] = B[i + 1] + (s[i + 1] == 'E');
    }

    int m = 2000000000;
    for(int i = 0; i < n; ++i) m = min(m, A[i] + B[i]);
    cout << m << endl;
}
