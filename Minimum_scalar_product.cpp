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
ll x[810],y[810];

int n;
bool cmp(int a,int b)  {  return a>b;  }

int main()
{
	int t;
	cin >> t;
	forr(T,1,t)
	{
		cin >> n;
		forr(i,1,n)
			cin >> x[i];

		ll prod = 0;
		forr(i,1,n)
			cin >> y[i];

		sort(x+1,x+n+1);
		sort(y+1,y+n+1,cmp);
		forr(i,1,n)
			prod += x[i]*y[i];

		printf("Case #%d: %I64d\n",T,prod );
	}	
	return 0;
}