#include<bits/stdc++.h>
using namespace std;
#define int long long
#define li cout<<__LINE__<<'\n'; 


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int m; cin>>m;
	while(m--)
	{
		bool fl=0;
		int n,s=0; cin>>n;
		int dec=1;
		if(n==1)
			s=1;
		while(n!=1)
		{
			
			if(fl) break;
			for(int i=9;i>0&&!fl;i--)
			{
				if(n%i==0)
				{
					s+=i*dec;
//					cout<<"S  "<<s<<'\n';
					n/=i;
					dec*=10; 
					break;
				}
				else if(i==2)
				{
					fl=1;
					break;
				}
			}
		}
		if(fl)   cout<<-1<<'\n';
		else     cout<<s<<'\n';
	}
		
}

/*

*/

