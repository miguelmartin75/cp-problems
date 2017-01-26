#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int i = 0;
    int n, m;
    while(cin >> n >> m)
    {
        if(n == 0 && m == 0)
            break;

        if(i > 0) 
        {
            cout << endl;
        }

        bool grid[100][100] = {};
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                char ch;
                cin >> ch;

                grid[i][j] = ch == '*';
            }
        }

        cout << "Field #" << i + 1 << ":" << endl;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(grid[i][j]) 
                {
                    cout << '*';
                    continue;
                }

                int c = 0;
                for(int x = -1; x <= 1; ++x)
                {
                    for(int y = -1; y <= 1; ++y)
                    {
                        if(x == 0 && y == 0) continue;
                        if(x + i < 0  || y + j < 0 ||
                           x + i >= n || y + j >= m)
                        {
                            continue;
                        }

                        c += grid[x + i][y + j];
                    }
                }

                cout << c;
            }
            cout << endl;
        }

        i += 1;
    }
}
