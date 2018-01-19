#include <bits/stdc++.h>
using namespace std;

struct TCPhoneHomeEasy
{
    int validNumbers(int digits, vector<string> prefix)
    {
        int amount = 1;
        for(int i = 0; i < digits; ++i) amount *= 10;

        for(auto& p : prefix)
        {
            int number = 1;
            for(int i = 0; i < digits - p.size(); ++i) number *= 10;
            amount -= number;
        }
        return amount;
    }
};

#ifdef LOCAL
int main(int argc, char *argv[])
{
    TCPhoneHomeEasy t;
    cout << t.validNumbers(7, {"0", "1", "911"}) << endl;
    cout << t.validNumbers(3, {"0", "1", "911"}) << endl;
    cout << t.validNumbers(3, {"111"}) << endl;
}
#endif // LOCAL
