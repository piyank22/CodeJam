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
int n,q;
int bit[max_n]; // here our bit represents the number of free locations up to the pos
int arr[max_n];

void bit_add(int pos,int x)
{
	while( pos <= n )
	{
		bit[pos] += x;
		pos += pos & -pos ;
	}
}

int bit_get(int pos)
{
	int ans=0;
	while( pos )
	{
		ans += bit[pos];
		pos -= pos & -pos ;
	}
	return ans;
}
int bin_search(int val)
{
	int s=0;
	int e=n+1;
	while(e-s>1)
	{
		int m=(s+e)>>1;
		if( bit_get(m) >=  val )
			e=m;
		else
			s=m;
	}
	return e;
}
int main()
{
	int t;
	cin >> t;
	forr(T,1,t)
	{
		cin >> n;
		cin >> q;
		memset( arr , -1 , sizeof arr );
		memset( bit ,  0 , sizeof bit );
		
		forr(i,1,n)
			bit_add(i,1);

		int pos=0;
		forr(i,0,n-1)
		{
			pos = (pos+i)%(n-i);
			// notice this
			// in bit whenever change occurs ( change of 1 can only occur )
			// it means it must be free
			// we binary search the lower bound of the required position
			// we have to search for pos+1
			
			int t = bin_search(pos+1); // this step takes logn^2 time
			
			arr[t] = i+1;
			bit_add(t,-1);
		}

		printf("Case #%d: ",T);
		forr(i,1,q)
		{
			int temp;
			cin >> temp ;
			cout << arr[temp] <<" ";
		}
		cout<<"\n";
	}
	return 0;
}
