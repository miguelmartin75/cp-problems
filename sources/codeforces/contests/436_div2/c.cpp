#include <bits/stdc++.h>
using namespace std;

int A, B, F, K;

int calc(int x, int i, int b)
{
    if(b < 0) return INT_MAX;
    else if(b == 0 && (K != i && x != F)) return INT_MAX;

    if(K == i) return 0;

    int dist_to_fuel = abs(x - F);

    int m = INT_MAX;
    if(x != F && b >= dist_to_fuel)
    {
        int fuel = calc(F, i, B);
        m = min(m, fuel + (fuel != INT_MAX));
    }

    int dest = i % 2 == 0 ? A : 0;
    int dist = abs(dest - x);
    m = min(m, calc(dest, i + 1, b - dist));

    return m;
}

int main(int argc, char *argv[])
{
    cin >> A >> B >> F >> K;

    int res = calc(0, 0, B);
    if(res != INT_MAX) 
        cout << res << endl;
    else
        cout << -1 << endl;
}
