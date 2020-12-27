#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    int t;
    cin >> t;

    for(int i = 0; i < t; ++i)
    {
        int salaries[3];
        for(auto& s : salaries)
        {
            int x;
            cin >> x;
            s = x;
        }

        sort(begin(salaries), end(salaries));
        cout << "Case " << i + 1 << ": " << salaries[1] << endl;
    }
}
