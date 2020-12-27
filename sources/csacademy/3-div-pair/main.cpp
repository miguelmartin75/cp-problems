#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    
    long long ans = 0;
    
    unordered_map<int, int> h;
    for(int i = 0; i < n; ++i) 
    {
        int x; cin >> x;
        x %= 3;
        
        int y = x == 0 ? 0 : 3 - x;
        ans += h[y];
        h[x]++;
    }
    
    cout << ans << endl;
}