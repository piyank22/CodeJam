#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <vector>

#define PI acos(-1)
#define ll long long
#define llu long long unsigned
#define mp make_pair
#define pb push_back
#define xx first
#define yy second
#define eps 1e-5
#define setzero(x) memset(&x,0,sizeof(x))
#define forr(i,a,b) for(int i = int(a) ; i<= int(b) ; i++ )
#define rof(i,a,b)  for(int i = int(a) ; i>= int(b) ; i-- )
#define sz(v) int(v.size())	
using namespace std;
const int max_n=1e6+7;
ll n,a,b,c,d,x,y,m,ans;
ll rem[3][3];

int main()
{
	int t;
	cin >> t;
	forr(T,1,t)
	{
		memset( rem , 0 , sizeof rem );

		cin >> n >> a >> b >> c >> d >> x >> y >> m;
		forr(i,1,n)
		{
			rem[ x%3 ][ y%3 ]++; 
			x = (a*x+b)%m;
			y = (c*y+d)%m;
		}

		ans=0;
		forr(i,0,2)
			forr(j,0,2)
				ans += ( rem[i][j] * (rem[i][j]-1) * (rem[i][j]-2) )/6;

		forr(i,0,2)
		{
			ans += rem[i][0]*rem[i][1]*rem[i][2];
			ans += rem[0][i]*rem[1][i]*rem[2][i];
		}

		forr(i,0,2)
			forr(j,0,2)
				forr(k,0,2)
					if( i!=j && i!=k && j!=k )
						ans += rem[0][i]*rem[1][j]*rem[2][k];

		printf("Case #%d: %lld\n",T,ans);
	}
	return 0;
}
