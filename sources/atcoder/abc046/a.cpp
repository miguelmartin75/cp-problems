#include <iostream>
#include <map>
using namespace std;

int main(int argc, char *argv[]) {
    int a, b, c;
    cin >> a >> b >> c;

    map<int, int> m;
    m[a]++;
    m[b]++;
    m[c]++;

    cout << m.size() << endl;
}
