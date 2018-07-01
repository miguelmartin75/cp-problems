#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n, m;
    cin >> n >> m;

    if(n > m) swap(n, m);

    int V = 2*(n - 1) + 1;
    int P = 2*(m - (n - 1) - 2);
    cout << P << " " << V << endl;
}
