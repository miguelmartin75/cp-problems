#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for(int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    for(int i = 0; i < Q; ++i)
    {
        int j, k;
        cin >> j >> k;
        int prev = j;
        int count = 0;
        for(int i = j; count < k && i < N; ++i)
        {
            if(A[i] > A[prev])
            {
                prev = i;
                count += 1;
            }
        }

        cout << prev << endl;
    }
}
