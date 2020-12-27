#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    int n, b, h, w;
    while(cin >> n >> b >> h >> w)
    {
        unsigned min_price = INT_MAX;
        for(int i = 0; i < h; ++i)
        {
            unsigned price;
            cin >> price;

            for(int j = 0; j < w; ++j)
            {
                int beds;
                cin >> beds;

                if(beds >= n)
                {
                    min_price = min(price, min_price);
                }
            }
        }

        if(min_price * n > (unsigned)b)
        {
            cout << "stay home" << endl;
        }
        else
        {
            cout << min_price * n << endl;
        }
    }
}
