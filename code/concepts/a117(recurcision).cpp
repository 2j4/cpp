#include<bits/stdc++.h>
using namespace std;
int cnt, n;

void mov(int n, char from, char to, char by)
{
    if (n <= 0)
        return;
    mov(n-1, from, by, to);
    cout << "ring " << n << " : " << from << " => " << to << '\n';
    cnt++;
    mov(n-1, by, to, from);
}

void div(int n, char from, char to, char by)
{
    if (n <= 0)
        return;
    mov(n-1, from, by, to);
    cout << "ring " << n << " : " << from << " => " << to << '\n';
    cnt++;
    div(n-2, by, from, to);
}

signed main()
{
	cin>>n;
	div(n, 'A', 'C', 'B');
	cout<<"共需"<<cnt<<"個移動\n"; 
}



