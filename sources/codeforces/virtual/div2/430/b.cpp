#include <bits/stdc++.h>
using namespace std;

double dist(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool on_crust(int R, int D, int x, int y, int r)
{
    const double distToCenter = dist(x, y, 0, 0);
    const double offsets[] = { 0, r, -r };
    for(double o : offsets)
    {
        if(distToCenter + o > R)
        {
            return false;
        }
        else if(distToCenter + o < R - D)
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    int R, D;
    cin >> R >> D;

    int n;
    cin >> n;

    int num = 0;
    for(int i = 0; i < n; ++i)
    {
        int x, y, r;
        cin >> x >> y >> r;

        if(on_crust(R, D, x, y, r))
        {
            num++;
        }
    }
    cout << num << endl;
}
