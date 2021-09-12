#include<iostream>
using namespace std;
int n,m,dp[202][202],res;
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	for(int i=1; i<201; i++) {
		for(int j=1; j<201; j++) {
			i==1&&j==1 ? dp[1][1]=1 :
			dp[i][j]=(dp[i][j-1]*i+dp[i-1][j-1])%1000000;
		}
	}
	while(cin>>n>>m&&n&&m){
		res=0;
		for(int i=1;i<=n;res+=dp[i][m],res%=1000000,i++);
		cout<<res<<'\n';
	}
	return 0;
}