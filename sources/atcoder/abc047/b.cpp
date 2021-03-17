#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int W, H, N;
    cin >> W >> H >> N;

    int leftX = 0, rightX = W;
    int botY = 0, topY = H;
    for (int i = 0; i < N; ++i)
    {
        int x, y, a;
        cin >> x >> y >> a;

        switch(a) {
            case 1:
                leftX = max(leftX, x);
                break;
            case 2:
                rightX = min(rightX, x);
                break;
            case 3:
                botY = max(botY, y);
                break;
            case 4:
                topY = min(topY, y);
                break;
        }
    }

    if(rightX < leftX || topY < botY) {
        cout << 0 << endl;
    } else {
        cout << ((rightX - leftX) * (topY - botY)) << endl;
    }
}
