#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    string s;
    cin >> s;

    auto first = s.find_first_of('A');
    auto last = s.find_last_of('Z');

    size_t ans = 0;
    if(last >= first)
    {
        ans = last - first + 1;
    }
    cout << ans << endl;
}
