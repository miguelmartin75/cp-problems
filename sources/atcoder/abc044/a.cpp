#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    int n, k, y, x;
    cin >> n >> k >> x >> y;

    int first_k = x * min(n, k);
    int last_k = max(0, (n - k) * y);
    cout << first_k + last_k << endl;
}
