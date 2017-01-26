#include <iostream>
#include <string>
using namespace std;

int main()
{
    pair<int, string> vals[52] = {};

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        for(int i = 0; i < 52; ++i)
        {
            string word;
            cin >> word;

            const int val = (word[0] >= '2' && word[0] <= '9') ? word[0] - '0' : 10;
            vals[51 - i].first = val;
            vals[51 - i].second = word;
        }

        // index 51 = bottom
        // index 0 = top
        // [0, 25) = cards taken away
        
        int y = 0;
        int top = 25;
        for(int i = 0; i < 3; ++i)
        {
            const int x = vals[top].first;
            y += x;
            top += 1 + (10 - x);
        }

        const int amount_of_cards = 52 - top;
        std::copy(vals + 25, vals + 25 + amount_of_cards, vals + top);

        cout << "Case " << i + 1 << ": " << vals[25 + amount_of_cards - y].second << endl;
    }
}
