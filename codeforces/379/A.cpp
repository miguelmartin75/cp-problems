#include <iostream>

int main(int argc, char *argv[])
{
    int a, b;
    std::cin >> a >> b;

    int ans = 0; 

    while(a > 0) 
    {
        ans += a;
        a /= b;
    }

    std::cout << ans << '\n';
}
