#include <iostream>
using namespace std;

int main()
{
    const int coins[] = { 1, 5, 10, 25, 50 };
    long long count[30001] = {};
    count[0] = 1;
    for(int coin : coins)
    {
        for(int i = 1; i <= 30000; ++i)
        {
            if(i - coin < 0) continue;
            count[i] += count[i - coin];
        }
    }

    int n;
    while(cin >> n)
    {
        int amount = count[n];
        if(amount == 1)
            cout << "There is only 1 way ";
        else
            cout << "There are " << count[n] << " ways ";
        cout << "to produce " << n << " cents change." << endl;
    }
}
