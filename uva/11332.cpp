#include <iostream>
#include <map>
using namespace std;

int f(int n)
{
    if(n < 10) return n;
    static map<int, int> m;
    if(m.count(n)) { return m[n]; }

    int s = 0;
    while(n > 0)
    {
        s += n % 10;
        n /= 10;
    }
    return f(s);
}

int main(int argc, char *argv[])
{
    int n;
    while(cin >> n)
    {
        if(n == 0)
            break;

        cout << f(n) << endl;
    }
}
