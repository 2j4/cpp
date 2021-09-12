#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N = 1010;
int n, m, dp[N][N], s[N], ss[N], cas;
signed main()
{
//	ios::sync_with_stdio(0), cin.tie(0);
	while(cin >> n >> m && n!=0 && m!=0){
		memset(dp, 0, sizeof(dp));
		for(int i=1; i<=n; i++) cin >> s[i];
		for(int i=1; i<=m; i++) cin >> ss[i];
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				if(s[i]==ss[j]) dp[i][j] = dp[i-1][j-1]+1;
				else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
		cout<<"Twin Towers #"<<++cas<<'\n';
		cout<<"Number of Tiles : "<<dp[n][m]<<'\n';
	}
}



