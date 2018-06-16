#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int& x : arr) cin >> x;

    int sum = 0;
    for(int x : arr)
    {
        if(x % 2 == 0) 
        {
            for(int i = 1; i <= 32; ++i)
            {
                if((1 << i) & x)
                {
                    sum += i;
                    break;
                }
            }
        }
    }

    cout << sum << endl;
}
