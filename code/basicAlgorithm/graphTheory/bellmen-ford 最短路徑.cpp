#include<bits/stdc++.h>
using namespace std;
vector< pair<int, int> >vec[500005];
int n, m, sta, en, dis[500005];

void bl()
{
    for(int k = 0; k < m; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(auto j:vec[i])
            {
                dis[j.first] = min(dis[j.first], dis[i] + j.second);
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
    dis[sta] = 0;
    bl();
    cout << dis[en] << '\n';
}
