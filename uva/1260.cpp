#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int>& a)
{
    int result = 0;
    for(int i = 1; i < a.size(); ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(a[j] <= a[i]) result += 1;
        }
    }
    
    cout << result << endl;
}

int main(int argc, char *argv[])
{
    int t;
    cin >> t;

    for(int i = 0; i < t; ++i)
    {
        vector<int> a;
        int n;

        cin >> n;
        for(int j = 0; j < n; ++j)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }

        solve(a);
    }
}
