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
#define forr(i,a,b) for(int i = int(a) ; i<= int(b) ; i++ )
#define rof(i,a,b)  for(int i = int(a) ; i>= int(b) ; i-- )

using namespace std;

vector< pair< int, pair<int,int> > > p; // xx is x cordinate , yy.xx is 0 for start 1 for end , yy.yy is interval number

int main()
{
	int t;
	cin >> t;
	forr(T,1,t)
	{
		p.clear();
		ll n , l1 , r1 , a , b , c1 , c2 , m;
		cin >> n >> l1 >> r1 >> a >> b >> c1 >> c2 >> m ;
		ll x = l1 , y = r1 ;
		p.pb( mp(l1,mp(0,1)) );
		p.pb( mp(r1+1,mp(1,1)) );

		forr(i,2,n)
		{
			ll z = ( (a*x %m ) + (b*y %m ) )%m ;
			ll w = ( (a*y %m ) + (b*x %m ) )%m ;
			x = (z+c1)%m ;
			y = (w+c2)%m ;
			p.pb( mp( min(x,y) , mp(0,i) ) );
			p.pb( mp( max(x,y)+1 , mp(1,i) ) );
		}
		sort( p.begin() , p.end() );

		set<int> currently_covering ; 
		int st;
		int alone_start;
		int alone_id=0;
		map<int,int> alone_map;
		int ans=0;
		forr(i,0,p.size()-1)
		{
			if(p[i].yy.xx == 0)
			{
				currently_covering.insert( p[i].yy.yy ) ;
				if( currently_covering.size()==1 )
					st=p[i].xx ;
			}
			else
			{
				currently_covering.erase( p[i].yy.yy ) ;
				if( currently_covering.size()==0 )
					ans += p[i].xx - st ;
			}

			if( alone_id==0 && currently_covering.size()==1 )
			{
				alone_id = *( currently_covering.begin() ) ;
				alone_start = p[i].xx ;
			}
			else if( alone_id!=0 && currently_covering.size()!=1 )
			{
				alone_map[alone_id] += p[i].xx - alone_start;
				alone_id = 0;
			}
		}
		int max_alone = 0;
		for(map<int,int>::iterator it=alone_map.begin() ; it!=alone_map.end() ; it++ )
		{
			max_alone = max( max_alone , it->second );
		}
		printf("Case #%d: %d\n",T,ans-max_alone);
	}
	return 0;
}