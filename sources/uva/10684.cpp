#include <iostream>
#include <numeric>
using namespace std;

int main()
{
    int n;
    while(true) 
    {
        cin >> n;
        if(n == 0) 
        {
            break;
        }

        int m = 0;
        int r = 0;
        for(int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;

            r += x;
            if(r < 0) r = 0;

            m = max(r, m);
        }

        if(m <= 0) 
        {
            cout << "Losing streak." << endl;
        }
        else
        {
            cout << "The maximum winning streak is " << m << "." << endl;
        }
    }
}
