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
#define eps 1e-5
#define forr(i,a,b) for(int i = int(a) ; i<= int(b) ; i++ )
#define rof(i,a,b)  for(int i = int(a) ; i>= int(b) ; i-- )

using namespace std;

pair< int,int > interval[500020] ;

int main()
{
	int t;
	cin >> t;
	forr(T,1,t)
	{
		memset(interval , 0 , sizeof(interval));
		ll n , l1 , r1 , a , b , c1 , c2 , m;
		cin >> n >> l1 >> r1 >> a >> b >> c1 >> c2 >> m ;
		interval[1].first = l1 ;
		interval[1].second = r1 ;
		ll x = l1 , y = r1 ;

		forr(i,2,n)
		{
			ll z = ( (a*x %m ) + (b*y %m ) )%m ;
			ll w = ( (a*y %m ) + (b*x %m ) )%m ;
			x = (z+c1)%m ;
			y = (w+c2)%m ;
			interval[i].first = min(x,y) ;
			interval[i].second = max(x,y) ;
		}
		sort( interval+1 , interval+n+1 );
		int ans = 1e9 + 10;
		forr(k,1,n)
		{
			stack< pair<int,int> > stk;
			forr(i,1,n)
			{
				if(i!=k)
				{
					if(stk.empty())
						stk.push( interval[i] );
					else if( stk.top().second < interval[i].first )
						stk.push( interval[i] );
					else if( stk.top().second < interval[i].second )
						stk.top().second = interval[i].second ;
				}
			}
			int temp=0;
			while(!stk.empty())
			{
				temp += stk.top().second - stk.top().first + 1 ;
				stk.pop() ;
			}
			ans = min( ans , temp );
		}

		printf("Case #%d: %d\n",T,ans );
	}
	return 0;
}