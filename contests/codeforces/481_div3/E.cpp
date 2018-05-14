#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n, w;
    cin >> n >> w;

    int A = 0;
    int B = w;
    int c = 0;
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;

        c += x;

        A = max(A, c);
        B = min(B, w + c);
        //cout << "c = " << c << ", A = " << A << ", B = " << B << endl;
    }

    int amount = max(0, B - A + 1);
    cout << amount << endl;
}
