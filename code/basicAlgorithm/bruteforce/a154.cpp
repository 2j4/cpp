#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N = 0;
int n, ans;
bool fl, used[20], uz; 
int uu[20];

bool check(int f){
	int ff=f;
	if(f<1234) return 0;
	for(int i=0; i<10; i++) uu[i]=0;
	if(f<10000) uu[0]=1;
	while(f>0){
		uu[f%10]++; f/=10;
	} 
	for(int i=0; i<10; i++){
		if(uu[i]>1) return 0;
		if(uu[i]==1 && used[i]==1) return 0;
	}		
	return 1;
}

void dfs(int a, int id){
	if(id>=5){
		if(a%n!=0) return;
		int f=a/n; uz=0;
		if(check(f)){
			fl=1; 
			cout<<a<<" / ";
			if(a/n<10000) cout<<0; 
			cout<<a/n<<" = "<<n<<'\n';
			return;
		}
		return;
	}
	for(int i=0; i<10; i++){
		if(!used[i]){
			used[i]=1;
			dfs(a*10+i, id+1);
			used[i]=0;
		}
	}
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	while(cin >> n && n){
		fl=0, ans=0, uz=0;
		memset(used, 0, sizeof(used));
		dfs(0, 0);	
		if(fl==0){
			cout<<"There are no solutions for "<<n<<".\n";
		}
		cout<<'\n';
	}
}
