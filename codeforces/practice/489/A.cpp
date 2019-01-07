#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using swap_pair = std::pair<int, int>;

std::vector<swap_pair> solve(std::vector<int>& n)
{
    std::vector<swap_pair> res;
    
    for(int i = 0; i < n.size(); ++i)
    {
        auto min_it = std::min_element(n.begin() + i, n.end());
        int j = min_it - n.begin();

        if(i != j && n[i] != n[j]) 
        {
            std::swap(n[i], n[j]);
            res.emplace_back(i, j);
        }

    }

    return res;
}

int main(int argc, char *argv[])
{
    int n;
    std::vector<int> input;
    std::cin >> n;

    for(int i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;
        input.push_back(x);
    }

    auto res = solve(input);

    std::cout << res.size() << '\n';
    for(auto& x : res)
    {
        std::cout << x.first << " " << x.second << "\n";
    }
}
