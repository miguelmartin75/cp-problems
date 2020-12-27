#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j) 
            cin >> A[i][j];


    long long result = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            bool important = true;
            for(int k = 0; k < n; ++k)
            {
                if(k == i || k == j) continue;

                if(A[i][k] + A[k][j] == A[i][j]) 
                {
                    important = false;
                    break;
                }
                else if(A[i][k] + A[k][j] < A[i][j])
                {
                    cout << -1 << endl;
                    return 0;
                }
            }

            if(important) result += A[i][j];
        }
    }

    cout << result << endl;
}
