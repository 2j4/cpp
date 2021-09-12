#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
typedef long long ll;
using namespace std;
const int N = 5e5+10;
struct node{
    ll id, cn;
};
bool operator>(node x, node y){
    return x.cn > y.cn;
}
ll sum[N];
vector<ll> e[N];
ll es[N], T, n, en;
bool use[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while(T--){
        memset(sum, 0, sizeof(sum));
        memset(use, 0, sizeof(use));
        for(int i=0;i<n;i++)  e[i].clear();
        ll ms = 0;
        
        cin >> n >> en;        
        for(ll i=0, a, b; i<en; i++){
            cin>>a>>b;
            if(a > b) swap(a, b);
            e[a].push_back(b);
            e[b].push_back(a);
            sum[a]++;
            ms = max(ms, sum[a]);
        }
        cout << ms << " ";
        ms = 0;
        priority_queue<node, vector<node>, greater<node> > con;

        for(int i=0; i<n; i++){
            es[i] = e[i].size();
            con.push({i, es[i]}); //node
        }
        for(int i=0;i<n;i++){
            ll nowc = con.top().cn;
            ll nowt = con.top().id;
            while(use[nowt]){
                con.pop();
                nowc = con.top().cn;
                nowt = con.top().id;
            }
            ms = max(ms, nowc);
            for(int j=0; j<e[nowt].size(); j++){
                if(use[ e[nowt][j] ]) continue;
                es[ e[ nowt][j] ]--;
                con.push(node{e[nowt][j], es[ e[ nowt][j] ] });
            }
            use[nowt] = 1;
            con.pop();
        }
        cout << ms << "\n";
    }
    return 0;
}