#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    int i = 0;
    string line;
    while(getline(cin, line))
    {
        if(line.empty()) break;

        i += 1;
        int n;
        cin >> n;

        cout << "Case " << i << ":" << endl;

        for(int k = 0; k < n; ++k)
        {
            int i, j;
            cin >> i >> j;
            cin.ignore();

            bool same = true;
            char prev = '\0';
            for(int x = max(0, min(i, j)); x <= min((int)line.size() - 1, max(i, j)); ++x)
            {
                if(prev == '\0')
                    prev = line[x];
                if(line[x] != prev)
                {
                    same = false;
                    break;
                }
            }

            cout << (same ? "Yes" : "No") << endl;
        }
    }

}
