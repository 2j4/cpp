#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N = 20000;
int a[N], n, t, d, l, poi, nw;

signed main(){
//	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	while(n--){
		memset(a, 0, sizeof(a));
		poi=1; nw=1;
		cin >> d >> l;
		for(int i=0; i<l; i++){
			poi=1;
			for(int j=0; j<d; j++){
				a[poi]=1;
				nw=poi;
				if(a[poi*2]==1){
					a[poi*2]=0;
					poi=poi*2+1;
				} else {
					poi=poi*2;
				}
			}
		}
		cout<<nw<<'\n';
	} 
}



