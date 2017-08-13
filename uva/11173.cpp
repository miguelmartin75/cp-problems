#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int n, k;
        cin >> n >> k;

        cout << (k ^ (k >> 1)) << '\n';
    }
    cout << flush;
}
