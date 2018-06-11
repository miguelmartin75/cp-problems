#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    long long n, m, a, b;
    cin >> n >> m >> a >> b;

    long long remove = n % m;
    long long add = m - remove;

    long long ans = min(a * add, b * remove);

    cout << ans << endl;
}
