#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    double max_ratio = 0.0;
    int m = 0;
    int s = 0;
    for(int a = 0; 100*A*a <= F; ++a)
    {
        for(int b = 0; 100*B*b + 100*A*a <= F; ++b)
        {
            const int water = 100*B*b + 100*A*a;
            for(int c = 0; water + c*C <= F; ++c)
            {
                for(int d = 0; water + c*C + d*D <= F; ++d)
                {
                    const int sugar = c*C + d*D;
                    if(100*sugar > water * E) continue;
                    if(sugar + water == 0) continue;

                    double ratio = (double)sugar / (water + sugar);
                    if(ratio > max_ratio)
                    {
                        max_ratio = ratio;
                        m = water + sugar;
                        s = sugar;
                    }
                }
            }
        }
    }
    cout << m << ' ' << s << endl;
}
