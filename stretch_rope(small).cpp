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
const int mod = 1e9+7;
int n,m,l;

vector< pair< pair<int,int> , int > > vec;
int main()
{
	int t;
	cin >> t;

	forr(T,1,t)
	{
		cin >> n >> m >> l;
		vec.clear();
		vec.resize(n);
		forr(i,0,n-1)
			cin >> vec[i].xx.xx >> vec[i].xx.yy >> vec[i].yy;

		int ans=101;
		forr(i,0,(1<<n)-1)
		{
			int t=i;
			int index=0;
			int left=0,right=0,price=0;
			while(t)
			{
				if(t&1)
				{
					left += vec[index].xx.xx;
					right += vec[index].xx.yy;
					price += vec[index].yy;
				}
				t=t>>1;
				index++;
			}
			if(price<=m && left<=l && l<=right )
				ans=min(ans,price);
		}
		printf("Case #%d: ",T);
		if(ans==101)
			cout<<"IMPOSSIBLE";
		else
			cout<<ans;
		cout<<"\n";
	}
	return 0;
}
