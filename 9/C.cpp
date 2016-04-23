#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::string n;
    std::cin >> n;
    
    int initial_amount = 0;

    bool assign_one = false;
    for(auto& x : n)
    {
        if(assign_one)
        {
            x = '1';
        }
        else if(x > '1')
        {
            assign_one = true;
        }
    }

    for(size_t i = 1; i < n.size(); ++i)
    {
        char ch = n[i];

        if(ch >= '1')
        {
            initial_amount = 2 * initial_amount + 1;
        }
        else
        {
            initial_amount *= 2;
        }
    }

    ++initial_amount;

    int amount = 0;
    for(int i = 0; i <= static_cast<int>(n.size()) - 2; ++i)
    {
        amount |= (1 << i);
    }

    amount += initial_amount;
    std::cout << amount << '\n';
}
