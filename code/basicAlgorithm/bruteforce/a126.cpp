#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 0;
int n, tmp[310], ans[310];
bool nfirst=0, vis[20][10];
pii d[8]={{-2, -1},{-1,-2},{-2,1},{-1,2},{1,-2},{2,-1},{1,2},{2,1}};

inline void print(){
	if(ans[n*3]==0){  cout<<'0'; return;}
	for(int i=1; i<=n*3; i++){
		cout<<ans[i]<<' ';
	} cout<<'\n';
}

inline bool compare(){
	for(int i=1; i<=n*3; i++){
		if(tmp[i]<ans[i]){
			return 1;
		} else if (tmp[i]>ans[i]){
			return 0;
		}
 	}
 	return 0;
}	

inline void update(){
	for(int i=1; i<=n*3; i++){
		ans[i] = tmp[i];
	}
}

inline bool pass(int x, int y){
	
	if(x>3||x<1||y>n||y<1||vis[x][y]) return 0;
	return 1;
}

void dfs(int x, int y, int poi){
//	cout<<"dfs "<<x<<' '<<y<<' '<<"\n";
	vis[x][y]=1;
	tmp[(x-1)*n+y]=poi;
//	cout<<"tmp "<<tmp[(x-1)*n+y]<<' '<<(x-1)*n+y<<" poi "<<poi<<"\n\n"; 
	if(poi==3*n){
//		print();
		if(nfirst && compare()) update();
		if(!nfirst) update();
		nfirst=1;
		return;
	}
	for(int i=0; i<8; i++){
		if(pass(x+d[i].fi, y+d[i].se)){
			dfs(x+d[i].fi, y+d[i].se, poi+1);
//			cout<<"pass "<<x+d[i].fi<<' '<<y+d[i].se<<' '<<poi<<'\n';
			vis[x+d[i].fi][y+d[i].se]=0;
		}
	}
}


signed main(){
//	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	dfs(1, 1, 1);
	print();
}



