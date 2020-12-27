#include <iostream>

int h(int height)
{
    if(height == 1) return 1;
    return h(height - 1) + height - 1;
}

int f(int n)
{
    if(n == 1)
    {
        return 1;
    }

    return f(n - 1) + h(n);
}

int main(int argc, char *argv[])
{
    int n;
    std::cin >> n;

    std::cout << f(n) << '\n';
}
