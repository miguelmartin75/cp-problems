#include <iostream>
using namespace std;

int main()
{
    int x;
    cin >> x;

    int result = 0;
    while(x > 0)
    {
        if(x & 1)
        {
            ++result;
        }
        x >>= 1;
    }

    cout << result << endl;
}
