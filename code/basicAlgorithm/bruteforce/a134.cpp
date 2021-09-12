#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N = 0;
int n, dy[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
vector<string>ans;
string ss;

bool cmp(string a, string b){
	if(a.size() == b.size()) return a<b;
	return a.size()<b.size();
}

bool leap(string s){
	int y=0;
	for(int i=0; i<4; i++){
		y=y*10+s[i]-'0';
	}
	return y%4==0 && (y%100!=0 || y%400==0); 
}

void gans(int mn, int da, string s){
	string cp=s;
	reverse(cp.begin(), cp.end());
	if(s!=cp) return;

	if(mn<=12){
		if(mn==2){
			if(leap(ss)){
				if(da<30) {
					ans.push_back(s);
				}
				
			} 
			else if(da<29){
				ans.push_back(s);
			}
		}
		else if(da<=dy[mn]){
			ans.push_back(s);
		}
	}
}

void check(string s){

//	cout<<s<<'\n';

	if(s.size()==8){
		int mn = (int)(s[4]-'0')*10+s[5]-'0';
		int da = (int)(s[6]-'0')*10+s[7]-'0';
		gans(mn, da, s);
//		cout<<mn<<' '<<da<<'\n';

	}
	if(s.size()==7){
		int mn1 = (int)(s[4]-'0')*10+s[5]-'0'; // 10/2
		int da1 = s[6]-'0';
		int mn2 = s[4]-'0';	// 1/02
		int da2 = (int)(s[5]-'0')*10+s[6]-'0';
		gans(mn1, da1, s);
		gans(mn2, da2, s);
//		cout<<mn1<<' '<<da1<<'\n'<<mn2<<' '<<da2<<'\n';

	}
	if(s.size()==6){
		int mn3 = s[4]-'0';
		int da3 = s[5]-'0';
		gans(mn3, da3, s);
	}

}

signed main(){
		ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	while(n--){
		ans.clear();
		
		cin >> ss;
		check(ss+ss[3]+ss[2]+ss[1]+ss[0]);
		check(ss+ss[2]+ss[1]+ss[0]);
		check(ss+ss[1]+ss[0]);
		
		sort(ans.begin(), ans.end(), cmp);
		cout<<ans.size()<<' ';
		for(auto aa:ans){
			cout<<aa<<' ';
		} 
		cout<<'\n';
	}
}



