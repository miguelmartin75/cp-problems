#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    vector<int> t;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        t.emplace_back(x);
    }

    int result = t[0] > 15 ? 15 : -1;

    if(result == -1)
        for(size_t i = 1; i < t.size(); ++i)
        {
            if(t[i] - t[i - 1] > 15)
            {
                result = t[i - 1] + 15;
                break;
            }
        }

    cout << (result == -1 ? min(90, t.back() + 15) : result) << endl;
}
