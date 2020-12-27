#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    unsigned a, b;

    while(cin >> a >> b)
    {
        if(a == 0 && b == 0)
            break;

        int num = 0;
        int carry = 0;
        while(a > 0 || b > 0)
        {
            if(carry) num++;

            int d1 = a % 10;
            int d2 = b % 10;

            int res = carry + d1 + d2;
            carry = res >= 10;

            a /= 10;
            b /= 10;
        }

        if(carry) num++;

        if(num)
        {
            cout << num;
        }
        else 
        {
            cout << "No";
        }
        cout << " carry operation";
        if(num > 1) cout << "s";
        cout << "." << endl;
    }
}
