#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if(a < b) swap(a, b);

    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(int argc, char *argv[]) {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int A = 1, B = 1;
    for(int i = 0; i < n; ++i) {
        int t, a;
        cin >> t >> a;

    }

    cout << A + B << endl;
}
