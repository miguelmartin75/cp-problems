#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    while(true)
    {
        int t;
        cin >> t;

        if(t == 0) break;

        int x, y;
        cin >> x >> y;

        const char* directions[][2] = 
        { 
            {"NE", "SE"}, // east
            {"NO", "SO"}  // west
        };

        for(int i = 0; i < t; ++i)
        {
            int x1, y1;
            cin >> x1 >> y1;

            if(x == x1 || y == y1)
            {
                cout << "divisa";
            }
            else
            {
                // x1 < x => west?
                // y1 < y => south?
                cout << directions[x1 < x][y1 < y];
            }

            cout << endl;
        }
    }
}
