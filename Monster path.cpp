#include <cstdio>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cstring>

#define PI acos(-1)
#define ll long long
#define eps 1e-5
#define forr(i,a,b) for(int i = int(a) ; i<= int(b) ; i++ )
#define rof(i,a,b)  for(int i = int(a) ; i>= int(b) ; i-- )

using namespace std;

int arr[21][21];
int visit[21][21];
double p,q;
int r,c;

int x[4]={1,0,-1,0};
int y[4]={0,-1,0,1};

double dfs(int i,int j,int l)
{
	if(l==0)
		return 0;
	double ans;
	double mm=0;
	forr(k,0,3)
	{
		ans=0;
		if( i+x[k]>=0 && i+x[k]<r && j+y[k]>=0 && j+y[k]<c )
		{
			if(arr[ i+x[k] ][ j+y[k] ] == 0)
				ans += pow(1.0-q,visit[ i+x[k] ][ j+y[k] ] )*q;
			else
				ans += pow(1.0-p,visit[ i+x[k] ][ j+y[k] ] )*p;

			visit[ i+x[k] ][ j+y[k] ]++;
			ans += dfs(i+x[k],j+y[k],l-1);
			visit[ i+x[k] ][ j+y[k] ]--;

			mm=max(ans,mm);
		}
	}
	return mm;
}

int main()
{
	int t;
	cin>>t;
	forr(k,1,t)
	{
		double ans=0;
		int i,j;
		int len;
		cin>>r>>c>>i>>j>>len;
		cin>>p>>q;
		memset(visit,0,sizeof(visit));
		forr(a,0,r-1)
		{
			forr(b,0,c-1)
			{
				char c;
				cin>>c;
				if(c=='.')
					arr[a][b]=0;
				else
					arr[a][b]=1;
			}
		}
		ans = dfs(i,j,len);
		printf("Case #%d: %.7lf\n",k,ans );
	}
}