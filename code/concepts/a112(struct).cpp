#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long
#define ll long long
using namespace std;
const int N = 1005;
struct P{
	string na;
	vector<pair<string, int>>ani;
}p[N];
int n, nm, us=-1;
string a, b;
bool f1, f2;

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin>>n;
	for(int i=0; i<n; i++){
		f1=0;
		cin >> a >> nm >> b;
		for(int j=0; j<=us; j++){
			f2=0;
			if(p[j].na == b){
				f1=1;
				
				for(int k=0; k<p[j].ani.size(); k++){
					if(p[j].ani[k].fi == a){
						f2=1;
						p[j].ani[k].se+=nm;
					}
				}
				if(f2==0){
					p[j].ani.push_back({a,nm});
				}
			}
		} 
		if(f1==0){
			p[++us].na=b;
			p[us].ani.push_back({a,nm});
		}
	}
	for(int i=0; i<=us; i++){
		cout<<p[i].na<<":";
		for(int j=0; j<p[i].ani.size()-1; j++){
			cout<<p[i].ani[j].fi<<' '<<p[i].ani[j].se<<',';
		} cout<<p[i].ani[p[i].ani.size()-1].fi<<' '<<p[i].ani[p[i].ani.size()-1].se<<'\n';
	}
}

/*
7
�U�l 2 ��W
�D 1 �a�W
�Q�t 2 ����
�� 1 ��W
�U�l 1 �a�W
�D 3 ��W
�U�l 3 ��W

��W:�U�l 5,�� 1,�D 3
�a�W:�D 1,�U�l 1
����:�Q�t 2
*/

