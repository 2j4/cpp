#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N = 0;
struct TK{
	int id, cost;
	vector<int>nxt; 
};
struct Nd{
	int cost, now, i;
	vector<int>ids;
};
class cmp{
	public:
		bool operator()(Nd &a, Nd &b){
			return a.cost > b.cost;
		} 
};
void print(Nd t){
	cout<<"Cost = "<<t.cost<<", Tickets used: "<<t.ids[0];
	for(int i=1; i<t.ids.size(); i++){
		cout<<", "<<t.ids[i];
	}
	cout<<'\n';
}
signed main()
{
//	ios::sync_with_stdio(0), cin.tie(0);
	vector<TK>tk[30]; 
	int n;
	cin>>n;
	for(int i=1; i<=n; i++){
		int cost, k, city[20];
		cin >> cost >> k;
		for(int j=0; j<k; j++){
			cin>>city[j];
		}
		vector<int>c(city+1, city+k);
		tk[city[0]].push_back({i, cost, c});
	}
	int k, city[15];
	cin>>k;
	for(int i=0; i<k; i++){
		cin >> city[i];
	}
	priority_queue<Nd, vector<Nd>, cmp>pq;
	for(auto i:tk[city[0]]){
		int p=1;
		for(auto j:i.nxt){
			if(p<k && j==city[p]) p++;
			pq.push({i.cost, j, p, {i.id}});
		}
	}
	
	while(!pq.empty()){
		Nd t = pq.top();
		pq.pop();
		if(t.i==k){
			print(t);
			break;
		}
		for(TK i:tk[t.now]){
			vector<int>v(t.ids);
			v.push_back(i.id);
			int p=t.i+1;
			for(int j:i.nxt){
				if(p<k && j==city[p]) p++;
				pq.push({i.cost+t.cost, j, p, v});
			}
		}
	}
}


