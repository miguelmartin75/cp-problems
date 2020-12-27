#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int p1 = 1;
    int p2 = 1;

    int sum = 0;
    while(true)
    {
        int curr = p1 + p2;

        if(curr >= 4000000)
            break;

        sum += curr % 2 == 0 ? curr : 0;

        p1 = p2;
        p2 = curr;
    }

    cout << sum << endl;
}
