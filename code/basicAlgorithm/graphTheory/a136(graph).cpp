#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N = 200;
int n, m, adj[30][30];

bool tra(int u, int v){
	if(adj[u][v]) return 1;
	for(int j=0; j<n; j++){
		if(adj[u][j] && tra(j, v)){
			return 1;
		}
	} return 0;
}

void dfs(int start, string &s){
	s+=('A'+start);
	for(int i=0; i<n; i++){
		if(adj[start][i]==1){
			dfs(i, s); return;
		}
	}
}

signed main(){
//	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	char edge[101][2]={};
	for(int i=1; i<=m; i++){
		cin >> edge[i][0] >> edge[i][1];
	}
	
	vector<bool>is_root(30, 1);
	bool over=0;
	for(int t=1; t<=m; t++){
		int u=edge[t][0]-'A', v=edge[t][1]-'A';
		if(tra(v, u)){
			cout<<"Order conflict after getting pair "<<t<<'\n';
			over=1;
			break;
		}
		
		if(!tra(u, v)){
			adj[u][v]=1;
			is_root[v]=0;
			
			for(int j=0; j<n; j++){
				if(tra(j, u)&&adj[j][v]) adj[j][v]=0;
				if(tra(v, j)&&adj[u][j]) adj[u][j]=0;
			}
		}
		
		int root=-1;
		for(int i=0; i<n; i++){
			if(is_root[i]) root=i;
		}
		string s="";
		dfs(root, s);
		if(s.size()==n){
			cout<<"Determine the testing sequence after getting pair "<<t<<" : "<<s<<'\n';
			over=1;
			break;
		}
	}
	if(!over) cout<<"No answer\n";
}



