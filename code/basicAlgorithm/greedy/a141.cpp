#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long
#define ll long long
#define tp top()
#define pii pair<int,int>
#define pb push_back
#define ep emplace
#define pt(x) cout<<x<<'\n';
using namespace std;
const int N = 5e6+5;
int n, k, a[N], pri, nw, rng, l, r; 
signed main()
{
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);	
	l=1, r=a[n]-a[1];
	while(l!=r){
		nw = 1;
		rng = (l+r)/2 + a[nw];
		for(int i=1; i<=k; i++){
			while(a[nw] <= rng){
				nw++;
				if(nw>n)
					break;
			}
			if(nw <= n){
				rng = (l+r)/2 + a[nw];
			}
			else {
				break;
			}
		}

		if(nw <= n) {
			l = (l+r)/2 + 1;
		}
		else{
			r = (l+r)/2;
		}
	}
	
	cout << l << '\n';
}
