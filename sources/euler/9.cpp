#include <iostream>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    for(int a = 1; a <= n; ++a)
    {
        for(int b = a + 1; ; ++b)
        {
            int c = n - (a + b);
            if(c < b || c < a) break;

            if(a*a + b*b == c*c)
            {
                cout << a << ", " << b << ", " << c << " = ";
                cout << a * b * c << endl;
            }
        }
    }
}
