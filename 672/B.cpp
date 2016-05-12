#include <iostream>
#include <string>
#include <numeric>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if(n > 26)
    {
        cout << -1 << endl;
        return 0;
    }

    int counts[26] = {};

    char ch;
    for(int i = 0; i < n; ++i)
    {
        cin >> ch;
        counts[ch - 'a']++;
    }

    int sum = 0;
    for(int i = 0; i < 26; ++i)
    {
        if(counts[i])
        {
            sum += counts[i] - 1;
        }
    }
    cout << sum << endl;
}
