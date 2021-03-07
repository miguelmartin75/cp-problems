#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    int n, k;
    cin >> n >> k;

    int ans = k;
    for(int i = 1; i < n; ++i) {
        ans *= (k-1);
    }
    cout << ans << endl;
}
