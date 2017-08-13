#include <algorithm>
#include <sstream>

vector<string> split(const string& str)
{
    vector<string> res;
    
    istringstream ss{str};
    
    string temp;
    while(getline(ss, temp, ' '))
    {
        res.emplace_back(temp);
    }
    
    return res;
}

int smallestFreq(const string& str)
{
    int counts[26] = {};
    for(char ch : str)
    {
        counts[ch - 'a']++;
    }
    
    for(int c : counts)
    {
        if(c == 0) continue;
        return c;
    }
    
    // should never occur
    return 0;
}

vector<int> freqTable(const string& str)
{
    vector<int> res;
    const auto split = ::split(str);
    res.reserve(str.size());
    
    for(auto& sp : split)
    {
        res.emplace_back(smallestFreq(sp));
    }
    
    return res;
}

vector<int> solution(string &A, string &B) 
{
    // solution is NlogN (bounded by sort)
    
    auto freqA = freqTable(A);
    auto freqB = freqTable(B);
    
    vector<int> result;
    result.reserve(freqB.size());
    
    // used to reserve order for result
    vector<int> indiciesB;
    indiciesB.reserve(freqB.size());
    for(int i = 0; i < static_cast<int>(freqB.size()); ++i) indiciesB.emplace_back(i);
    
    // sort both arrays - NlogN
    sort(freqA.begin(), freqA.end());
    sort(indiciesB.begin(), indiciesB.end(), [&freqB](int i, int j) { return freqB[i] < freqB[j]; });
    
    // use two pointers to compute result in O(N)
    int i1 = 0;
    int i2 = 0;
    
    int sum = 0;
    while(i2 < static_cast<int>(freqB.size()))
    {
        const int realI2 = indiciesB[i2];
        
        if(i1 < static_cast<int>(freqA.size()))
        {
            const int a = freqA[i1];
            const int b = freqB[realI2];

            if(a < b)
            {
                sum++;
                i1++;
                continue; // skip
            }
        }
        
        result.emplace_back(sum);
        i2++;
    }
    
    // re-order according to indicies
    vector<int> real_result;
    real_result.reserve(indiciesB.size());
    for(int i = 0; i < static_cast<int>(indiciesB.size()); ++i)
    {
        real_result.emplace_back(result[indiciesB[i]]);
    }
    
    return real_result;    
}
