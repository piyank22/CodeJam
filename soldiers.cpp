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

int main()
{
	int t;
	cin>>t;
	vector< pair<int,int> > arr,temparr ;
	forr(k,1,t)
	{
		arr.clear();
		int n;
		cin >> n;
		forr(i,0,n-1)
		{
			int a,d;
			cin >> a >> d;
			arr.pb( mp(a,d) );
		}

		printf("Case #%d: ",k );
		bool ans = false;

		while( arr.size() > 0 )
		{
			temparr.clear();

			int max_x=0, max_y=0 ;
			forr(i,0,arr.size()-1)
			{
				max_x = max( max_x , arr[i].first );
				max_y = max( max_y , arr[i].second );
			}
			
			forr(i,0,arr.size()-1)
				if( arr[i].first == max_x && arr[i].second == max_y )
				{
					ans = true;
					break ; 
				}

			forr(i,0,arr.size()-1)
				if( arr[i].first < max_x && arr[i].second < max_y )
					temparr.pb( arr[i] );

			arr = temparr;
		}
		if(ans)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}