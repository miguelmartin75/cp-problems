#include <iostream>
#include <string>

std::string to_excel(int x);
int from_excel(const std::string& x);

int main(int argc, char *argv[])
{
    int N;
    std::cin >> N;
    std::cin.ignore();

    std::string line;
    for(int i = 0; i < N; ++i)
    {
        std::getline(std::cin, line);
        if(line.empty()) continue;

        enum class State {
            ADD_TO_COL,
            ADD_TO_ROW
        } state = State::ADD_TO_ROW;

        int row = 0;
        int col = 0;
        bool seen_num = false;

        // if this string is empty:
        // that means that the input is in the form of:
        // RXCY
        std::string temp;

        for(auto ch : line)
        {
            bool is_num = ch >= '0' && ch <= '9';

            if(seen_num && state == State::ADD_TO_ROW && ch == 'C') 
            {
                temp.clear();
                state = State::ADD_TO_COL;
            } 
            else if(is_num)
            {
                int& x = state == State::ADD_TO_ROW ? row : col;
                x = x * 10 + (ch - '0');
                seen_num = true;
            }
            else // is_letter
            {
                temp += ch;
            }

        }

        if(!temp.empty())
        {
            col = from_excel(temp);
            std::cout << "R" << row << "C" << col;
        }
        else 
        {
            std::cout << to_excel(col) << row;
        }

        std::cout << '\n';
    }
}

std::string to_excel(int x) 
{
    std::string str;
    while(x > 0)
    {
        x -= 1;
        const int digit = x % 26;
        str = static_cast<char>('A' + digit) + str;
        x /= 26;
    }
    return str;
}

int from_excel(const std::string& x) 
{
    int res = 0;
    for(auto ch : x)
    {
        res = res * 26 + (ch - 'A' + 1);
    }
    return res;
}

