#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int t;
    cin >> t;

    for(int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;


        int high = 0;
        int low = 0;
        int prev = -1;
        for (int j = 0; j < n; ++j)
        {
            int x;
            cin >> x;

            if(prev != -1)
            {
                if(prev > x) low += 1;
                else if(prev < x) high += 1;
            }

            prev = x;
        }

        cout << "Case " << i + 1 << ": " << high << " " << low << endl;
    }
}
