#include<iostream>
#include<algorithm>
const int E = 5000005,
          V = 100005;
int p[V];
struct edge
{
    int x, y, c;
} e[E];
bool operator<(edge e1, edge e2)
{ 
    return e1.c < e2.c; 
}

int fp(int x)
{
    return x == p[x] ? x : (p[x] = fp(p[x]) );
}

void uni(int x, int y)
{
    p[ fp(x) ] = fp(y);
}

int main()
{
    for(int i = 0; i < n; p[i] = i, i++);
    for(int i = 0; i < m; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        e[i].x = a,
        e[i].y = b,
        e[i].c = cost;
    }
    sort(e, e+E);

    int i, j;
    for(i = 0, j = 0; i < V-1 && j < E; j++)
    {
        if(fp(e[j].x) == fp(e[j].y))
        {
            continue;
        }

        uni(e[j].x, e[j].y);
        i++;
    }
}