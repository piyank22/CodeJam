#include <cstdio>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <sstream>

#define PI acos(-1)
#define ll long long
#define eps 1e-5
#define forr(i,a,b) for(int i = int(a) ; i<= int(b) ; i++ )
#define rof(i,a,b)  for(int i = int(a) ; i>= int(b) ; i-- )

using namespace std;

int arr[3002][3002];
int n,m;

int number_of_monsters(int i,int j,int a, int b)
{
	i--;
	j--;
	return arr[a][b] - arr[i][b] - arr[a][j] + arr[i][j];
}

ll solve()
{
	int k=min(n,m);
	ll an=0;
	forr(siz,2,k)
	{
		ll ans=0;
		forr(i,1,n-siz+1)
		{
			forr(j,1,m-siz+1)
			{
				if( number_of_monsters(i,j,i+siz-1,j+siz-1) == 0 )
				{
					ans++;
				}
			}
		}
		an += ans;
	}
	return an;
}

int main()
{
	int t;
	cin>>t;
	forr(kk,1,t)
	{
		ll ans=0;
		int k;
		cin>>n>>m>>k;
		memset(arr,0,sizeof(arr));
		int u,v;
		forr(i,0,k-1)
		{
			cin>>u>>v;
			arr[u+1][v+1]=1;
		}
		forr(i,1,n)
			forr(j,1,m)
				arr[i][j]=arr[i][j] + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];

		ans = solve()+(n*m)-k;
		printf("Case #%d: ",kk);
		cout << ans << endl;
	}
}

