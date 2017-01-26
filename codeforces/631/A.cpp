#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    int n;
    std::vector<int> a;
    std::vector<int> b;

    std::cin >> n;

    for(int i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;
        a.push_back(x);
    }

    for(int i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;
        b.push_back(x);
    }

    int max = 0;
    for(int l = 0; l < n; ++l)
    {
        for(int r = l + 1; r <= n; ++r)
        {
            int c1 = 0;
            int c2 = 0;
            for(int i = l; i != r; ++i)
            {
                c1 |= a[i];
                c2 |= b[i];
            }

            int current = c1 + c2;
            max = std::max(max, current);
        }
    }

    std::cout << max << std::endl;
}
