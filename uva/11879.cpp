#include <iostream>
#include <string>
using namespace std;

string mul(int c, const string& n)
{
    string res;

    int carry = 0;
    for(int i = n.size() - 1; i >= 0; --i)
    {
        const int n_i = n[i] - '0';
        const int ir = n_i * c + carry;
        res += ((ir % 10) + '0');
        carry = (ir / 10);
    }

    return res;
}

string sub(string s1, string s2)
{
    if(s1.size() < s2.size() || s1 < s2)
    {
        swap(s1, s2);
    }

    int i1 = s1.size() - 1;
    int i2 = s2.size() - 1;

    while(i1 >= 0 && i2 >= 0)
    {
        const int n1 = 

        int sum = 
    }

    return "";
}

bool is_div_17(const string& num)
{
    static map<string, bool> cache;

    if(num.size() > 2)
    {
        string new_num = num.substr(0, num.size() - 1);
        string d5 = mul("5", num.back());
        string test_num = sub(new_num, d5);
        
        bool res = is_div_17(test_num);
        cache[num] = res;
        return res;
    }
    
    return num == "17";
}

int main(int argc, char *argv[])
{
    string num;
    while(getline(cin, num))
    {
        if(num == "0")
        {
            break;
        }

        cout << is_div_17(num) << endl;
    }
}
