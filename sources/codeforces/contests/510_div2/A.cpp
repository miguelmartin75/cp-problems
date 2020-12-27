#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int& x : a) cin >> x;

    int max_el = *max_element(a.begin(), a.end());
    int max_k = max_el + m;

    int stepsToMax = 0;
    for(int x : a) {
        stepsToMax += max_el - x;
    }
    m -= stepsToMax;

    if(m < 0) m = 0;

    int min_k = max_el + m / n;
    if(m % n != 0) min_k++;

    cout << min_k << ' ' << max_k << endl;
}
