#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    vector<int> X(3);
    for(int& x : X) cin >> x;

    sort(X.begin(), X.end());

    if(X[0] + X[1] == X[2] || X[0] == X[1] + X[2]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
