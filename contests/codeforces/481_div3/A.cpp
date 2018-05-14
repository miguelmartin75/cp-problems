#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    map<int, bool> seen;
    vector<int> result;
    for(int i = n - 1; i >= 0; --i)
    {
        int x = arr[i];
        if(seen[x]) continue;
        result.emplace_back(x);
        seen[x] = true;
    }

    
    cout << result.size();
    cout << endl;

    for(int i = result.size() - 1; i >= 0; --i)
        cout << result[i] << ' ';

    cout << endl;
}
