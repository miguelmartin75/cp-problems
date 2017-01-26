#include <iostream>
#include <cmath>

using int_type = long long;

int main(int argc, char *argv[])
{
    int_type n, m, a;
    std::cin >> n >> m >> a;

    int_type result = 0;

    int_type horizontal = static_cast<int_type>(std::ceil(static_cast<double>(n) / a));
    int_type vertical = static_cast<int_type>(std::ceil(static_cast<double>(m) / a));

    // if both directions overfill
    if(n <= a && m <= a)
    {
        result = 1;
    }
    else if(n <= a)
    {
        result = vertical;
    }
    else if(m <= a)
    {
        result = horizontal;
    }
    else
    {
        result = horizontal * vertical;
    }

    std::cout << result << '\n';
}
