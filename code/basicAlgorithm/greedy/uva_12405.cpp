#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int m,cnt=0; cin>>m;
	while(m--)
	{
		cnt++;
		string str;
		int n,ans=0; cin>>n>>str;
		for(int i=0;i<n;i++)
		{
			if(str[i]=='.')
			{
				if(i+2<n)
					ans++,
					str[i+1]='#',
					str[i+2]='#';
				else if(i+1<n)
					ans++,
					str[i+1]='#';
				else
					ans++;
			}
		}cout<<"Case "<<cnt<<": "<<ans<<'\n'; 
	}
		
}

/*

*/

