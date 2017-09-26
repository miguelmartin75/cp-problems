#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    int sum = 0;
    int min_odd = INT_MAX;
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if(x > 0) sum += x;
        if(x % 2 != 0) min_odd = min(abs(x), min_odd);
    }
    if(sum % 2 == 0) sum -= min_odd;
    cout << sum << endl;
}
