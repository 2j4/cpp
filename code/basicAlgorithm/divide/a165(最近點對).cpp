#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5;
struct P {double x, y;} p[N+10], t[N+10];
int n;
bool cmpx(P a, P b){ return a.x < b.x; }
bool cmpy(P a, P b){ return a.y < b.y; }
double cal(P a, P b){ return sqrt( (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) ); }

double dnc(int l, int r){
	if(l>=r) return 1e9;
	int m = (l+r)/2;
	double dis = min(dnc(l, m), dnc(m+1, r));
	int cnt=0;
//	cout<<"tp ";
	for(int i=m; i>=l && p[m].x - p[i].x < dis; i--){
		t[cnt++] = p[i];
//		cout<<i<<' ';
	} 
	for(int i=m+1; i<=r && p[i].x - p[m].x < dis; i++){
		t[cnt++] = p[i];
//		cout<<i<<' ';
	} 
//	/cout<<'\n';
	
	sort(t, t+cnt, cmpy);
//	for(int i=0; i<cnt; i++) cout<<t[i].x<<' ';cout<<'\n';
	for(int i=0; i < cnt; i++){
		for(int j=1; j<4 && i+j < cnt; j++){
//			cout<<"cal "<<t[i].x<<' '<<t[i+j].x<<'\n';
			dis = min(dis, cal(t[i], t[i+j]));
//			cout<<cal(t[i], t[i+j])<<' '<<dis<<'\n';
		}
	}
	return dis;
}

signed main(){
//	ios::sync_with_stdio(0), cin.tie(0);
	while(cin >> n && n){
		memset(p, 0, sizeof(p));
		memset(t, 0, sizeof(t));
		for(int i=0; i<n; i++) cin >> p[i].x >> p[i].y;
		sort(p, p+n, cmpx);
		double res = dnc(0, n-1);
		if(res >= 100000.0) cout << "INFINITY\n";
		else cout << fixed << setprecision(4) << res << '\n';
	}
}



