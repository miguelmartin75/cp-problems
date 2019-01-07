#include <bits/stdc++.h>
using namespace std;

void print(int k)
{
    int bit = (1 << 3);
    while(bit > 0)
    {
        cout << (((bit & k) == bit) ? 1 : 0);
        bit >>= 1;
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    long long n, k;
    cin >> n >> k;

    vector<int> A(n, 0);
    vector<int> B(n, 0);

    long long ans = 0;
    for(int i = 0; i < n; ++i)
    {
        cin >> A[i] >> B[i];
        if((A[i] & k) == A[i]) ans += B[i];
    }

    for(int bit = (1 << 30); bit > 0; bit >>= 1)
    {
        if(!(bit & k)) continue;

        long long valid_bits = (bit - 1) | (k ^ bit);

        long long total = 0;
        for(int i = 0; i < n; ++i)
        {
            const long long a = A[i]; 
            const long long b = B[i];

            if((a & valid_bits) != a) continue;

            total += b;
        }
        ans = max(total, ans);
    }

    cout << ans << endl;
}
