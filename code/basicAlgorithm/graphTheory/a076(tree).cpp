#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N = 2048;
int a[N], poi=1, n, h=1, mx=0;
bool use[N];
signed main()
{
//	ios::sync_with_stdio(0), cin.tie(0);
	while(cin>>n){
		poi=1; h=1;
		while(use[poi]){
			if(n < a[poi]){
				poi*=2;
			} else {
				poi=poi*2+1;
			}
			
			h++;
		}
		a[poi]=n;
		use[poi]=1;
		mx=max(h, mx);
	}
	cout<<mx<<'\n';
}



