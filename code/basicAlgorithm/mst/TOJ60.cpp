#include<iostream>
using namespace std;
const int N = 1000005;
struct edge {
    int x, y, w;
}e[N];
bool operator<(edge e1, edge e2) { return e1.c < e2.c; }
int p[N], n, m, k;
vector<int>we;

inline void init(){
    for(int i=0; i<n; p[i]=i, i++);
}

int fp(int x){
    return x == p[x] ? x : ( p[x] = fp(x) );
}

int uni(int x, int y){
    p[ fp(x) ] = fp(y);
}

int main(){
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        cin >> e[i].x >> e[i].y >> e[i].w;
    }
    if(k == -1|| k == n){
        cout << "0\n";
    }
    init();
    sort(e, e+n);
    for(auto u : )
}