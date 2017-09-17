#include <iostream>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    map<int, int> counts;
    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        counts[x] += 1;
    }

    long long l1 = -1;
    long long l2 = -1;
    bool done = false;
    for(auto it = counts.rbegin(); !done && it != counts.rend(); ++it)
    {
        int len = it->first;
        int& amount = it->second;
        while(amount >= 2)
        {
            amount -= 2;
            if(l1 == -1) l1 = len;
            else if(l2 == -1) l2 = len;
            else
            {
                done = true;
                break;
            }
        }
    }

    if(l1 == -1 && l2 == -1)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << l1 * l2 << endl;
    }
}
