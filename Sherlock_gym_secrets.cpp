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
#define mp make_pair
#define pb push_back
#define eps 1e-5
#define forr(i,a,b) for(int i = int(a) ; i<= int(b) ; i++ )
#define rof(i,a,b)  for(int i = int(a) ; i>= int(b) ; i-- )

using namespace std;

const ll mod = 1e9 + 7;

ll fast_power( ll a , ll b , ll mod ) // a^b
{
	ll res  = 1 % mod ;
	while( b )
	{
		if( b & 1 == 1 )
			res = res * a % mod ;
		a = a*a % mod ;
		b = b >> 1 ;
	}
	return res % mod ;
}

ll first[1000010] ;
ll second[1000010] ;

int main()
{
	int t;
	cin>>t;
	forr(T,1,t)
	{
		memset(first,0,sizeof(first));
		memset(second,0,sizeof(second));

		ll ans = 0 ;
		ll a , b , n , k ;
		cin >> a >> b >> n >> k ;
		forr(i,1, min(n,k) )
		{
			int t ;
			t = fast_power(i,a,k) ;
			first[t] = ( first[t] + (n-i)/k + 1 ) % mod ;
			
			t = fast_power(i,b,k) ;
			second[t] = ( second[t] + (n-i)/k + 1 ) % mod ;
		}

		forr(i,0,k-1)
		{
			int r1 = i;
			int r2 = (k-i) % k;
			ans = (ans + (first[r1] * second[r2]) ) % mod ;
		}

		forr(i,1, min(n,k) )
			if( ( fast_power(i,a,k) + fast_power(i,b,k) )%k == 0 )
				ans = (ans - (1 + ((n-i)/k) ) ) % mod;

		printf("Case #%d: %lld\n",T,(ans+mod) % mod) ;
	}
	return 0;
}