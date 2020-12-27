#include <iostream>
using namespace std;

int main()
{
    long long x, y;
    while(cin >> x >> y)
    {
        if(y < x) swap(x, y);
        cout << y - x << endl;
    }
}
