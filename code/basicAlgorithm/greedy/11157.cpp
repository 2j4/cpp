#include<bits/stdc++.h>
using namespace std;
bool issmall[105];
bool isvisit[105];
int position[105];
int N;

int getmindis()
{
	int mindis=position[0];
	for(int i=0;i<N;i++)
	{
		if(issmall[i])
			mindis=max(mindis,position[i+2]-position[i]),i++;
		else if(is)
			mindis=max(mindis,position[i+1]-position[i]);
		
		isvisit[i]=1;
	}
	for (int i = N; i > 0; --i)
    {
        if (!isvisit[i-1] || !isSmall[i-1])
            mindis=max(mindis,position[i]-position[i-1]);
        else
            mindis=max(mindis,position[i]-position[i-2]),i--;
    }
    return mindis;
}

int main()
{
	int D;
	cin>>N>>D;
	for(int i=0;i<N;i++)
	{
		char type, a;  
		cin>>type>>a>>position[i];
		issmall[i]=(type=='S');
		isvisit[i]= 0;
	}

	position[N]=D;
	issmall[N] =0;
	issvist[N] =0;	

	int mindis=getmindis();
	cout<<mindis<<'\n';
}


/*
ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
*/

