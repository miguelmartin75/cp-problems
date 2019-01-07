#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int t;
    cin >> t;

    for(int i = 0; i < t; ++i)
    {
        int e, n;
        cin >> e >> n;

        vector<int> vec(n);
        for(int i = 0; i < n; ++i) cin >> vec[i];

        sort(vec.begin(), vec.end());

        int i1 = 0;
        int i2 = vec.size() - 1;

        int h = 0;
        while(i2 >= i1)
        {
            if(vec[i1] < e)
            {
                e -= vec[i1];
                ++i1;
                ++h;
            }
            else if(h > 0 && i2 - i1 >= 1)
            {
                e += vec[i2];
                --i2;
                --h;
            }
            else { break; }
        }

        cout << "Case #" << i + 1 << ": " << h << endl;
    }
}
