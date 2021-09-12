#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 0;
int n, k;

bool ck(int q){
	while(q>0){
		if( (q%10 )%2==1) return 0;
		q/=10; 
	}
	return 1;
}

signed main()
{
	cin >> n;
	while(n--){
		cin>>k;
		int a = (int)sqrt(pow(10, k-1));
		int b = (int)sqrt(pow(10, k));
		for(int i=a; i<=b; i++){
			int c = i*i;
			if(ck(c)){
				cout<<c<<'\n';
				break;
			}
		}
	}
}



