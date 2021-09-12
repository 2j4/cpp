#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N = 100010;
int col[N], n, m, cnt[2], ans;
vector<int>adj[N];
bool vis[N], er;

void dfs(int u, bool c){
	if(er) return;
	col[u]=c;
	cnt[c]++;
	for(auto v:adj[u]){
		if(col[v]==col[u]) er=1;
		if(col[v]==-1){
			dfs(v, !c);
		}
	}
}

signed main(){
//	ios::sync_with_stdio(0), cin.tie(0);
	memset(col, -1, sizeof(col));
	cin >> n >> m;
	for(int i=0, a, b; i<m; i++){
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for(int i=1; i<=n && !er; i++){
		cnt[0]=0, cnt[1]=0;
		if(col[i]==-1){
			dfs(i, 0); 
		}
		ans+=min(cnt[0], cnt[1]);
	}
	cout<<(er?0:ans)<<'\n';
}



