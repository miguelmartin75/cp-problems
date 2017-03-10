#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    vector<int> vec;
    vec.reserve(10000);

    int x;
    while(cin >> x)
    {
        vec.emplace_back(x);

        std::partial_sort(vec.begin(), vec.begin() + vec.size() / 2 + 1, vec.end());

        long long med = vec[vec.size() / 2];

        if(vec.size() % 2 == 0)
        {
            med += vec[vec.size() / 2 - 1];
            med /= 2;
        }

        cout << med << endl;
    }
}
