#include <algorithm>

bool smaller(vector<int>& A, int K, int i, int j)
{
    // can't cache frequency of characters akin to previous question,
    // as A is not guarenteed to be sorted
    int end = i + K;
    while(i < end)
    {
        if(A[i] != A[j])
        {
           // sort in descending order
           return A[i] > A[j]; 
        }
            
        i++;
        j++;
    }
    return false;
}

/*
The initial solution I produced on paper was the naive way (double loop over all contigious sub-arrays). 
However, I decided to change it to a sorting based approach, as it is clearly superior.

I chose to use nth_element as this is O(N) on average as it's quickselect. An atlernative is to use a sorting
based-algorithm which will achieve O(NlogN). However, since quickselect is essentially quicksort there's
no point in sorting in my opinion.
*/
vector<int> solution(vector<int> &A, int K) 
{
    // edge case |A| == K => whole vector
    if(static_cast<int>(A.size()) == K) return A;
    
    auto comparator = [&A, K](int i, int j)
    {
        return smaller(A, K, i, j);
    };
    
    vector<int> indicies;
    indicies.reserve(A.size());
    
    const int NUM_CONTIG = static_cast<int>(A.size()) - K + 1;

    // edge case A.size() == K => does nothing hence why I have the if
    // statement at the top of the function
    for(int i = 0; i < NUM_CONTIG; ++i)
    {
        indicies.emplace_back(i);
    }
    
    // get the largest element in the array - O(N) average time
    // I believe this is quickselect
    nth_element(indicies.begin(), indicies.begin(), indicies.end(), comparator);
    
    int biggestIndex = indicies[0];
    vector<int> result;
    result.reserve(K);
    for(int i = 0; i < K; ++i)
    {
        result.emplace_back(A[biggestIndex + i]);
    }
    return result;
}
