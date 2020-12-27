#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	int ans=-1,l=1,r=101;
	int x=0,y=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		if(y==1)l=max(l,x);
		else{
			l=max(l,x/y+(x%y==0?0:1));
			r=min(r,(x-1)/(y-1));
		}
	}
	cout<<l<<" "<<r<<endl;
	for(int i=l;i<=r;i++)
	{
		int x=n/i+(n%i==0?0:1);
        //cout << x << endl;
		if(ans==-1)ans=x;
		else if(ans!=x){cout<<-1;return 0;}
	}
	cout<<ans;
}
