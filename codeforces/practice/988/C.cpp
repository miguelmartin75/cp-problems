#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int k;
    cin >> k;

    unordered_map<int, pair<int, int>> s;
    for(int a = 0; a < k; ++a)
    {
        int n; cin >> n;

        vector<int> seq(n);
        for(int& x : seq) { cin >> x; }
        int sum = accumulate(seq.begin(), seq.end(), 0);

        for(int j = 0; j < n; ++j)
        {
            int x = sum - seq[j];
            if(s.count(x))
            {
                auto b = s[x];

                cout << "YES" << endl;
                cout << a + 1 << ' ' << j + 1 << endl;
                cout << b.first + 1 << ' ' << b.second + 1 << endl;

                return 0;
            }
        }

        for(int j = 0; j < n; ++j)
        {
            int x = sum - seq[j];
            s[x] = {a, j};
        }
    }


    cout << "NO" << endl;
}
