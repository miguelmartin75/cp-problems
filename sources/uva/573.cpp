#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char *argv[])
{
    int h, u, d, f;
    while(cin >> h >> u >> d >> f)
    {
        if(h == 0)
            break;

        const float dec = (f / 100.f) * u;

        bool succ = false;
        int day = 0;
        float pos = 0;
        float delta = u;
        while(pos <= h && pos >= 0)
        {
            ++day;

            pos += delta;
            if(pos > h)
            {
                succ = true;
                break;
            }

            pos -= d;
            if(pos < 0)
            {
                break;
            }

            delta -= dec;
            delta = max(0.f, delta);
        }

        if(succ) cout << "success ";
        else cout << "failure ";

        cout << "on day ";
        cout << day << endl;
    }
}
