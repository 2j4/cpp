#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N = 1000000;
string s, bin[8]={"000", "001", "010","011","100","101","110","111"}, ans;
int n;
bool er;
char nw;
signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	getline(cin, s);
	for(;n--;){
		getline(cin, s);
		int len = s.size(), cnt=0, cns=0;
		ans="", er=0, nw=s[0]; 
		for(int i=0; i<len; i++){
			if(s[i]!='0'&&s[i]!='1'){
				er=1;
				break;
			} else if(s[i]!=nw || s[i]==nw && cnt==7){
				ans+=nw+bin[cnt]+' ';
				cns++;
				cnt=1;
				nw=s[i];
			} else{
				cnt++;
			}
		}
		ans+=nw+bin[cnt]+' ';
		cns++;
		if(er){
			cout<<"-1\n";
		} else {
			cout<<ans;
			if((cns*4000/len)%10>4) cout<<cns*400/len+1<<"%\n";
			else cout<<cns*400/len<<"%\n";
		}
	}
}



