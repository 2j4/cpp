#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N = 100;
int n, ans[20], cas;
bool pri[N], used[10];

void mkprime(){
	for(int i=2; i<N; i++) pri[i]=1;
	for(int i=2; i<N; i++){
		if(pri[i]){
			for(int j=2; j*i<N; j++){
				pri[i*j]=0;
			}
		}
	}
}

void dfs(int x, int id){
	ans[id]=x;
	if(id==n){
		if(!pri[x+1]) return;
		for(int i=1; i<=n; i++) if(!pri[ans[i]+ans[i+1]]) return;
		for(int i=1; i<=n; i++) cout<<ans[i]<<' '; cout<<'\n';
		return;
	}
	for(int i=2; i<=n; i++){
		if(!used[i] && pri[ans[id]+i]){
			used[i]=1;
			dfs(i, id+1);
			used[i]=0;
		}
	}
}

signed main(){
//	ios::sync_with_stdio(0), cin.tie(0);
	mkprime();
	
	while(cin >> n){
		memset(used, 0, sizeof(used));
		memset(ans, 0, sizeof(ans));
		ans[1]=1; cas++; ans[n+1]=1;	
		cout<<"Case "<<cas<<":\n";
		dfs(1, 1);
	}
	
}



