#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#define int long long
using namespace std;
const int N = 1e6+10;
vector<pair<int, int>>nd[N];
pair<int, int>far[3];
int n, ord, m;
bool vis[N];

void dfs(int u, int dis){
    vis[u] = 1;
    if(dis > far[ord].second){
        far[ord].first = u;
        far[ord].second = dis;
    }
    for(auto v:nd[u]){
        if(!vis[v.first]){
            dfs(v.first, dis+v.second);
        }
    }
}

signed main(){    
    while(cin >> n && n){
        memset(far, 0, sizeof(far));
        memset(vis, 0, sizeof(vis));
        for(int i=0; i<N; i++) nd[i].clear(); 
        ord = 0;   
        int a, b, c;

        for(int i=0; i<n-1; i++){    
            cin >> a >> b >>c;
            nd[a].push_back({b, c});
            nd[b].push_back({a, c});
        }
        
        dfs(b, 0);
        memset(vis, 0, sizeof(vis));  ord++;
        dfs(far[0].first, 0);
        cout << far[1].second << '\n';
    }
    
}