#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[])
{
    int y, x, s;
    while(cin >> y >> x >> s)
    {
        int sum = x + y;
        int denom = sum - s - 1;
        double pCar = (double)x / sum;
        double pCow = (double)y / sum;

        double pCarPickedCar = (double)(x - 1) / denom;
        double pCarPickedCow = (double)x / denom;

        double ans = pCar * pCarPickedCar + pCow * pCarPickedCow;
        cout << fixed;
        cout << setprecision(5);
        cout << ans << endl;
    }
}
