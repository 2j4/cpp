#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<queue>
#define pii pair<int, int>
#define W first
#define U second
#define dbg cout << __LINE__ << '\n';
using namespace std;
const int N = 1e4+5;
vector<int>pt[N];
int t, n, m, s, d[N], a, b, mx, h[N], d2[N], ans1, ans2, hh;
bool vis[N], ff;

inline void bfs1(){
    queue<int>qw;
    qw.push(s); 
    d2[s] = 0;
    memset(vis, 0, sizeof(vis));
    vis[s] = true;
    ff = false;
    while(!qw.empty()){
        int tp = qw.front();  qw.pop(); mx = s;
        if (h[tp] == hh){
            ans1 = d2[tp];
            return;
        }
        for(auto x:pt[tp]){
            if(!vis[x]){
                if(h[x] < h[mx]) mx = x;
            }
        }
        if (h[mx] < h[tp]){
            for(auto x:pt[tp]){
                if(!vis[x] && h[x] == h[mx]){
                    vis[x] = true;
                    d2[x] = d2[tp]+1;
                    qw.push(x);
                }
            }
        }
    }
    ff = true;
}

inline void bfs2(){
    queue<int>q;
    q.push(s);  
    memset(vis, 0, sizeof(vis));
    d[s] = 0;
    vis[s] = true;
    while(!q.empty()){
        int tp = q.front();  q.pop();
        if(h[tp] == hh){
            ans2 = d[tp];
            return;
        }
        for(auto x:pt[tp]){
            if(!vis[x]){
                vis[x] = true;
                d[x] = d[tp]+1;
                q.push(x);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    for(int i=1; i<=t; i++){
        ans1=0, ans2=-1;
        hh = 2147483647;
        cin >> n >> m >> s;
        for(int i=0; i<n; i++){
            cin >> h[i];
            pt[i].clear();
            if (h[i] < hh){
                hh = h[i];
            }
        }
        for(int i=0; i<m; i++){
            cin >> a >> b;
            pt[a].emplace_back(b);
            pt[b].emplace_back(a);
        }
        bfs1();
        bfs2();
        if(ff&&ans2==-1)cout<< "Case #" << i << ": "<<"Call 119!\n"; 
        else cout << "Case #" << i << ": " << abs(ans1 - ans2*6 )<< '\n';
    }
    return 0;
}