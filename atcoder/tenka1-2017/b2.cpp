#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <string>
#include <set>
#include <map>
#define SIZE 100005
 
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
 
int A[SIZE],B[SIZE];
 

#include <iostream>
void print(int k)
{
    int bit = (1 << 3);
    while(bit > 0)
    {
        cout << (((bit & k) == bit) ? 1 : 0);
        bit >>= 1;
    }
    cout << endl;
}
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d %d",&A[i],&B[i]);
	ll ret=0;
	for(int i=0;i<n;i++) if((k|A[i])==k) ret+=B[i];
	for(int i=0;i<=30;i++)
	{
		if(!(k>>i&1)) continue;
		ll now=0;
		for(int j=0;j<i;j++) now|=1<<j;
		for(int j=i+1;j<=30;j++) if(k>>j&1) now|=1<<j;
        cout << "i = " << i << ", now = " << endl;
        print(now);

		ll sum=0;
		for(int j=0;j<n;j++) if((now|A[j])==now) { 
            cout << "a = " << A[j] << endl;
            sum+=B[j];
        }
		ret=max(ret,sum);
	}
	printf("%lld\n",ret);
	return 0;
}
