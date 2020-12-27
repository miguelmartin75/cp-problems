#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    if(n == 1) 
    {
        cout << 0 << endl;
        return 0;
    }

    vector<int> a(1 << n);
    vector<int> rollM(1 << n);
    cin >> a[0];
    rollM[0] = a[0];
    for(int i = 1; i < (1 << n); ++i)
    {
        int x;
        cin >> x;
        a[i] = x;
        rollM[i] = max(rollM[i - 1], a[i]);
    }

    vector<int> k(1 << n + 1);
    k[1] = a[0] + a[1];

    cout << "===" << endl;
    cout << "a0 = " << a[0] << ", a1 = " << a[1] << endl;
    cout << k[1] << '\n';
    for(int j = 2; j < (1 << n); ++j)
    {
        int maxI = (j & ~(j - 1) - 1);
        k[j] = a[j] + rollM[maxI];

        cout << "j = " << j << ", ";
        cout << "i <= " << maxI << endl;
        for(int i = 0; i < n; ++i)
        {
            if(j & (1 << i) && (1 << i) != j)
            {
                cout << "i == " << (1 << i) << endl;
                k[j] = max(k[j], a[j] + a[1 << i]);
            }
        }

        k[j] = max(k[j], k[j - 1]);
        cout << k[j] << '\n';
    }
}
