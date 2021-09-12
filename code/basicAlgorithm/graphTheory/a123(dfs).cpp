#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N = 100010;
struct tree{
	vector<int>cld;
	int cdn, par, mxn;
}t[N];
int n, k, a, root, ans;
bool vis[N];

void dfs(int u){
	vis[u]=1;
	for(auto v:t[u].cld){
		if(!vis[v]){
			dfs(v);
			t[u].mxn = max(t[u].mxn, t[v].mxn+1);
		}
	}
}

signed main()
{
//	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> k;
		for(int j=0; j<k; j++){
			cin >> a;
			t[i].cld.push_back(a);
			t[i].cdn++;
			t[a].par=i;
		}
	}
	
	for(int i=1; i<=n; i++){
		if(t[i].par==0){
			root = i;
			break;
		}
	}
	
	dfs(root);
	for(int i=1; i<=n; i++){
		ans+=t[i].mxn;
	}	
	cout<<root<<'\n';
	cout<<ans<<'\n';
}



