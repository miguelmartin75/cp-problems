#include <iostream>

int main(int argc, char *argv[]) {
    int a, b, c;
    std::cin >> a >> b >> c;

    int five =  (a == 5) + (b == 5) + (c == 5);
    int seven = (a == 7) + (b == 7) + (c == 7);

    std::cout << (five == 2 && seven == 1 ? "YES" : "NO") << std::endl;
}
