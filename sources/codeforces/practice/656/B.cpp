#include <iostream>
#include <iomanip>
#include <vector>

int main(int argc, char *argv[])
{
    int N;
    std::vector<int> M;
    std::vector<int> R;
    
    std::cin >> N;

    for(int i = 0; i < N; ++i)
    {
        int x;
        std::cin >> x;
        M.push_back(x);
    }

    for(int i = 0; i < N; ++i)
    {
        int x;
        std::cin >> x;
        R.push_back(x);
    }

    constexpr const int DAY_COUNT = 1000000;
    int days_to_clean = 0;
    for(int day = 0; day < DAY_COUNT; ++day)
    {
        for(int i = 0; i < N; ++i)
        {
            if(day % M[i] == R[i])
            {
                ++days_to_clean;
                break;
            }
        }
    }

    double ans = days_to_clean / (double)DAY_COUNT;
    std::cout << std::setprecision(6) << std::fixed << ans << '\n';
}
