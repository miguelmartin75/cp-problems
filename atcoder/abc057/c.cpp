#include <iostream>
#include <cmath>
using namespace std;

int num_digits(long long x)
{
    int c = 0;
    while(x > 0)
    {
        c++;
        x /= 10;
    }
    return c;
}

int main(int argc, char *argv[])
{
    long long n;
    cin >> n;

    int min_f = 100000000;
    for(long long i = 1; i * i <= n; ++i)
    {
        if(n % i != 0)
        {
            continue;
        }

        long long a = i;
        long long b = n / i;

        int f = max(num_digits(a), num_digits(b));

        min_f = min(f, min_f);
    }

    cout << min_f << endl;
}
