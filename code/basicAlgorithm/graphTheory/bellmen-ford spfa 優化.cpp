#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;
vector< pair<int, int> >vec[10005];
queue<int> que;
int n, m, sta, en, dis[10005];
bool vis[10005];

void bl()
{
    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        vis[u] = 0;
        for(auto i : vec[u])
        {
            if(dis[i.first] > dis[u] + i.second)
            {
                dis[i.first] = dis[u] + i.second;
                if (!vis[i.first])
                {
                    que.emplace(i.first);
                }
                
            }
        }
    }
}

int main()
{
    memset(dis, 1e9+10, sizeof(dis));      
	cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        vec[a].push_back({b, cost});
        vec[b].push_back({a, cost});
    }    
    cin >> sta >> en;
    que.emplace(sta);
    dis[sta] = 0;
    bl();
    cout << dis[en] << '\n';
}
