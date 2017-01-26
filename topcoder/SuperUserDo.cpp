#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class SuperUserDo 
{
public:

   int install(vector <int> A, vector <int> B)
   {
       bool libs[1001] = {};

       for(int i = 0; i < A.size(); ++i)
       {
           int a = A[i];
           int b = B[i];

           for(int x = a; x <= b; ++x)
           {
               libs[x] = true;
           }
       }

       return accumulate(begin(libs), end(libs), 0);
   }
    
};

int main(int argc, char *argv[])
{
    SuperUserDo user;
    cout << user.install({1, 2}, {1000, 1000}) << endl;
}
