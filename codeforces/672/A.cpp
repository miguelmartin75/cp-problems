#include <iostream>
#include <string>
using namespace std;

int main()
{
    int x;
    cin >> x;

    string str;

    for(int i = 1; str.length() < x; ++i)
    {
        str += to_string(i);
    }

    cout << str[x - 1] << endl;
}
