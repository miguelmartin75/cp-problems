#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;

        map<char, int> val;
        for(int i = 0; i < k; ++i)
        {
            char ch;
            int v;

            cin >> ch >> v;
            val[ch] = v;
        }

        long long result = 0;

        int m;
        cin >> m;
        cin.ignore();

        for(int i = 0; i < m; ++i)
        {
            string line;
            getline(cin, line);

            for(auto& ch : line)
            {
                result += val[ch];
            }
        }

        printf("%d.%0.2d$\n", result / 100, result % 100);
    }
}

