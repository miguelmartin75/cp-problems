#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    int parent[1000000] = {};
    int i = 0;
    string line;
    while(getline(cin, line))
    {
        if(line.empty()) break;

        parent[0] = line[0] == '1' ? 1 : 0;
        for(int i = 1; i < line.size(); ++i)
        {
            if(line[i - 1] != line[i])
            {
                parent[i] = parent[i - 1] + 1;
            }
            else
            {
                parent[i] = parent[i - 1];
            }
        }

        i += 1;
        int n;
        cin >> n;

        cout << "Case " << i << ":" << endl;

        for(int k = 0; k < n; ++k)
        {
            int i, j;
            cin >> i >> j;
            cin.ignore();

            const bool same = parent[i] == parent[j];

            cout << (same ? "Yes" : "No") << endl;
        }
    }
}
