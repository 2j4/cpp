#include<iostream>
#include<string.h>
#include<stdio.h>
#define ll cout<<__LINE__<<'\n'; 
using namespace std;
string a, b;
int f[10005];
int n, m, ans;

void mfail()
{
    for(int i = 1, j = 0; i < b.size(); i++, j++, f[i] = j)
    {
        while(j != -1 && b[i] != b[j])
		{
			j = f[j];
		} 
    }
    
}

void cmp()
{
    for(int i = 0, j = 0; i < a.size(); i++, j++)
    {
    	cout << "i " << i << " j " << j << '\n';
        while(j != -1 && a[i] != b[j])
		{
			cout  << "diffrent "<< i << ' ' << j << '\n';
			j = f[j];
		} 
        if(j == b.size()-1)
        {
        	cout << "same " << i-j <<'\n';
        	ans++;
        	// i -= j;
		}
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 0; i < n ;i++)
	{
        cin >> a >> m;
		for(int j = 0; j < m; j++)
		{
			ans = 0;
			memset(f, -1, sizeof(f));
            cin >> b;
            if(b.size() == 1)
            {
            	for(auto i:a)
            	{
            		if(i == b[0])
            		{
            			ans++;
					}
				}
			}
			else
			{	
				mfail();
    	        cmp();
			}
            cout << ans << '\n';
            cout << "\n\n"; 
		}  
	}
        
        

}
