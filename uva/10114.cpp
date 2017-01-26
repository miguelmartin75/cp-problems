#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int m;
    float down;
    float loan;
    int n;
    while(cin >> m >> down >> loan >> n)
    {
        if(m < 0)
        {
            break;
        }

        int owed = loan;
        int val = down + loan;
        int month;

        int down_m;
        float down_p;
        cin >> down_m >> down_p;

        cout << endl;
        for(month = 0; month < n; ++month)
        {
            if(month > 0 && owed < val)
            {
                break;
            }

            while(month > down_m)
            {
                cin >> down_m >> down_p;
            }

            cout << "owed = " << owed << endl;
            cout << "val = " << val << endl;
            owed -= down;
            val = val * (1 - down_p);
        }

        cout << month + 1 << " month";
        if(month > 0)
        {
            cout << "s";
        }
        cout << endl;
    }
}
