#include <iostream>

int main(int argc, char *argv[])
{
    int n;
    std::cin >> n;

    long long x = n < 13 ? (1ll << n) : (8092ll << (n - 13));
    std::cout << x << std::endl;
}
