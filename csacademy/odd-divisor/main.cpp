#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int a, b;
    cin >> a >> b;
    
    int ans = 0;
    vector<int> counts(b + 1, 0);
    for(int j = 1; j <= b; ++j)
    {
        for(int i = 0; i + j <= b; i += j) {
            counts[i + j]++;
            if(i + j >= a) {
                if(counts[i + j] % 2 != 0) ++ans;
                else --ans;
            }
        }
    }
    
    cout << ans << endl;
}