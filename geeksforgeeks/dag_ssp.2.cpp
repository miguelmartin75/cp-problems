#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[])
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for(int i = 0; i < t; ++i) 
    {
        int n;
        cin >> n;

        n -= 1;

        vector<int> sol(n + 1, 0);
        sol[0] = 0;

        for(int j = 1; j <= n; ++j) 
        {
            sol[j] = 1 + sol[j - 1];
            if((j + 1) % 3 == 0) 
            {
                sol[j] = min(sol[j], 1 + sol[j/3]);
            }
        }

        cout << sol[n] << endl;
    }
}
