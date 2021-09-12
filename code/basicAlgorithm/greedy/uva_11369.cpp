#include<bits/stdc++.h>
using namespace std;
int arr[20005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n; cin>>n;
	while(n--)
	{
		int ans=0;
		int m;  cin>>m;
		for(int i=0;i<m;i++)
			cin>>arr[i];
		sort(arr,arr+m);
		for(int i=m-3;i>=0;i-=3)
			ans+=arr[i];
		cout<<ans<<'\n';
	}	
}

/*

*/

