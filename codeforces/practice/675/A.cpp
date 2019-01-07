#include <iostream>
#include <numeric>
using namespace std;

int main(int argc, char *argv[])
{
    int a, b, c;
    cin >> a >> b >> c;

    int i = c == 0 ? 0 : abs((b - a) / c);
    bool ye = a + c * i == b;

    cout << (ye ? "YES" : "NO") << endl;
}
