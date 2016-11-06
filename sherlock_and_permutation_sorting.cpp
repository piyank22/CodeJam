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

using namespace std;

ll fact[5010] ;
ll chunk[5010] ;
ll sum[5010] ;
ll sq_sum[5010] ;

int main()
{
	int t;
	cin >> t;
	forr(T,1,t)
	{
		int n,m ;
		cin >> n >> m ;
		setzero(fact);
		setzero(chunk);
		setzero(sum);
		setzero(sq_sum);

		fact[0]=1%m;
		forr(i,1,n)
			fact[i]=(i*fact[i-1])%m ;
		
		chunk[0]=0;
		forr(i,1,n)
		{
			chunk[i] = fact[i] ;
			forr(j,1,i-1)
				chunk[i] = (m + chunk[i] - (fact[i-j]*chunk[j])%m )%m ;
		}

		sum[0]=0;
		forr(i,1,n)
		{
			forr(j,1,i)
				sum[i] = ( sum[i]  + ((sum[i-j] + fact[i-j])*(chunk[j]))%m )%m;
		}
		sq_sum[0]=0;
		forr(i,1,n)
		{
			forr(j,1,i)
				sq_sum[i] = (sq_sum[i] + ((sq_sum[i-j] + 2*sum[i-j] + fact[i-j])*chunk[j] )%m  )%m ;
		}
		printf("Case #%d: %d\n",T,(sq_sum[n])%m );
	}	
	return 0;
}