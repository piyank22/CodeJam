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

ll a,b,p;
const int max_n=1e6+7;

int sieve[max_n];
vector<int> prime;
ll arr[max_n];

int parent[max_n];
int siz[max_n];

int sizee;

void pre()
{
	for(ll i=2;i<max_n;i++)
		if(sieve[i]==0)
		{
			prime.pb(i);
			for(ll j=i*i;j<max_n;j+=i)
				sieve[j]=1;
		}
}

ll findd(ll a)
{
	while( parent[a]!=a )
	{
		ll temp=parent[a];
		parent[a]=parent[temp];
		a=temp;
	}
	return a;
}
void mergee(ll a,ll b)
{
	a=findd(a);
	b=findd(b);
	if(a==b)
		return;
	sizee--;
	if(siz[a]>siz[b])
	{
		parent[b]=a;
		siz[a]+=siz[b];
	}
	else
	{
		parent[a]=b;
		siz[b]+=siz[a];
	}
}
int main()
{
	pre();
	int t;
	cin >> t;
	forr(T,1,t)
	{
		cin >> a >> b >> p;
		vector<int>::iterator it, st = lower_bound( prime.begin() , prime.end() , p );

		sizee = b-a+1;
		for(ll i=1;i<=b-a+1;i++)
		{
			arr[i]=a+i-1;
			parent[i]=i;
			siz[i]=1;
		}
		for(it=st;it!=prime.end();it++)
		{
			ll start = (*it) * ceil(1.0*a/(*it));
			ll ende = (*it) * floor(1.0*b/(*it));
			for(ll k=start+(*it) ; k<=ende ; k += (*it) )
				mergee(start-a+1,k-a+1);
		}
		printf("Case #%d: %lld\n",T,sizee);
	}
	return 0;
}
