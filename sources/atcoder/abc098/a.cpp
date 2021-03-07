#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    int a, b;
    cin >> a >> b;

    cout << max(max(a - b, a + b), a * b) << endl;
}
