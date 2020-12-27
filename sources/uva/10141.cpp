#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    int n, p;
    for(int i = 0; cin >> n >> p; ++i)
    {
        if(n == 0 && p == 0)
        {
            break;
        }

        if(i > 0)
        {
            cout << endl;
        }

        cin.ignore();

        for (int i = 0; i < n; ++i)
        {
            string str;
            getline(cin, str);
        }

        struct {
            string name;
            float price = 0;
            int n_reqs = 0;
        } best;

        for (int i = 0; i < p; ++i)
        {
            string name;
            getline(cin, name);

            float price;
            int r;
            cin >> price >> r;

            if(best.n_reqs < r || (best.n_reqs == r && best.price > price))
            {
                best.name = name;
                best.n_reqs = r;
                best.price = price;
            }

            cin.ignore();
            for(int j = 0; j < r; ++j)
            {
                getline(cin, name);
            }
        }

        cout << "RFP #" << i + 1 << '\n';
        cout << best.name << endl;
    }
}
