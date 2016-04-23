#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    std::string n;
    std::cin >> n;
    
    int initial_amount = 0;

    if(n[0] == '1') 
    {

        bool assign_one = false;
        for(size_t i = 1; i < n.size(); ++i)
        {
            if(assign_one)
            {
                n[i] = '1';
            }
            if(n[i] > '1')
            {
                assign_one = true;
            }
        }

        bool found_large = false;
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

        if(!found_large) ++initial_amount;
    }
    else
    {
        initial_amount = (1 << (n.size() - 1));
    }

    int amount = 0;
    for(int i = 0; i <= static_cast<int>(n.size()) - 2; ++i)
    {
        amount |= (1 << i);
    }

    amount += initial_amount;
    std::cout << amount << '\n';
}
