#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    int x;
    cin >> x;

    for(int i = x + 1; i <= 9012; ++i)
    {
        int digits[4] = {};
        int num = i;
        bool skip = false;
        for(int j = 0; num > 0; ++j)
        {
            const int d = num % 10;
            num /= 10;

            int* end = digits + j;
            auto it = std::find(digits, end, d);
            if(it == end)
            {
                digits[j] = d;
            }
            else
            {
                skip = true;
                break;
            }
        }

        if(skip) continue;

        cout << i << endl;
        break;
    }
}
