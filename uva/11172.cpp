#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i)
    {
        int x, y;
        cin >> x >> y;

        if(x == y)
        {
            cout << '=';
        }
        else 
        {
            cout << (x < y ? '<' : '>');
        }

        cout << endl;
    }
}
