#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char *argv[])
{
    int t;
    cin >> t;

    for(int i = 0; i < t; ++i)
    {
        int p, x, y;
        cin >> p >> x >> y;

        int x1 = x - 50;
        int y1 = y - 50;
        double r = 50;

        double dot = (y1 * r) / (double)(r * sqrt(x1*x1 + y1*y1));
        double angle = acos(dot) * (180.0 / M_PI);

        if(x < 50) { angle = 360 - angle; }

        cout << "Case #" << i + 1 << ": ";

        bool a = angle <= p * 3.6;
        bool d = x1*x1 + y1*y1 <= 50*50;

        if(a && d)
        {
            cout << "black\n";
        }
        else
        {
            cout << "white\n";
        }
    }
}
