#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N = 0;
int sq[1000000], k, q;
bool ans;
signed main()
{
//	ios::sync_with_stdio(0), cin.tie(0);
	cin >> k;
	q = 1<<k;
	for(int i=1; i<=(sqrt(q/4)); i++){
		for(int j=i; j<=(sqrt((q-i*i)/3)); j++){
			for(int k=j; k<=sqrt((q-i*i-j*j)/2); k++){
				for(int l=k; l<=sqrt(q-i*i-j*j-k*k); l++){
					if(i*i + j*j + k*k + l*l == q){
						cout << i << ' ' << j << ' ' << k << ' ' << l << '\n';
						ans = 1;
					}
				}
			}
		}
	}
	if(!ans) cout << 0 << '\n';
}



