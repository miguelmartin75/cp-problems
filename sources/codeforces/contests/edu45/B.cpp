#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for(int& x : A) cin >> x;

    sort(A.begin(), A.end());

    int ans = 0;
    int i = 1;
    for(int j = 0; j < n; ++j)
    {
        while(i < n && !(A[i] > A[j])) ++i;
        if(i == n) break;

        if(A[i] > A[j] && A[i] <= A[j] + k) 
        {
            ++ans;
        }
    }

    cout << n - ans << endl;
}
