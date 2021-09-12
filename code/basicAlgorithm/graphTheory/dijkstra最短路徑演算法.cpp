#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<stdio.h>
#define pii pair<int, int>
using namespace std;
vector<pii>vec[10005];
priority_queue<pii, vector<pii>, greater<pii> >pq;
int n, m, en, sta, dis[10005];
bool vis[100005];

void djs()
{
    while(!pq.empty())
    {
        int w = pq.top().first,
            u = pq.top().second;
        pq.pop();
        if (dis[u] < w) continue;
        for(pii v: vec[u])
        {
            if(dis[v.second] > w + v.first)
            {
                dis[v.second] = w + v.first;
                pq.push({dis[v.second], v.second});
            }
        }
    }
}

int main()
{
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    cin >> n >> m;
    for(int i = 0;i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        vec[x].push_back({w, y});
        vec[y].push_back({w, x});
    }

    cin >> sta >> en;
    dis[sta] = 0;
    pq.push({0 , sta});
    djs();
    cout << dis[en] << '\n';
}


