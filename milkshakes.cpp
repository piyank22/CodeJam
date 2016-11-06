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

int like[2010][2010];
int done[2010];
int cnt[2010];
int state[2010];
vector<int> effect[2010]; // list corresponding to each flavour which customes are to be satisfied
int n,m;

int main()
{
	int t;
	cin >> t;
	forr(T,1,t)
	{
		cin >> n >> m;
		memset( like , -1 , sizeof like );
		memset( done ,  0 , sizeof done );
		memset( state, -1 , sizeof state );
		memset( cnt  ,  0 , sizeof cnt );
		forr(i,1,n)
			effect[i].clear();

		forr(i,1,m)
		{
			cin >> cnt[i];
			forr(j,1,cnt[i])
			{
				int k,l;
				cin >> k >> l;
				like[i][k]=l;
				effect[k].pb(i);
			}
		}

		bool fail = false;
		forr(i,1,m)
		{
			forr(j,1,m) // if not done and nothing left for customer j to satisfy
				if( done[j]==0 && cnt[j]==0 ) { fail=true; break; } // if fail is true than it means it is impossible to satisfy
			if(fail) break;

			int k=-1;
			forr(j,1,m)
				if( done[j]==0 && cnt[j]==1 ) { k=j; break; } // this means that customer j is not satisfied and there is only one way he can be satisfied
			if(k<0) break; // if there is no customer left unsatisfied we exit
		
			forr(j,1,n)
				if( like[k][j]>=0 && state[j]==-1 )
				{
					state[j] = like[k][j];
					vector<int>::iterator it;
					for(it = effect[j].begin() ; it!=effect[j].end() ; it++)
						if( like[*it][j] == like[k][j] )
							done[*it]=1;
						else
							--cnt[*it];
					break;
				}
		}

		printf("Case #%d: ",T);
		if(fail)
			cout<<"IMPOSSIBLE";
		else
		{
			forr(i,1,n)
				if(state[i]==-1||state[i]==0)
					cout<<"0 ";
				else
					cout<<"1 ";
		}
		cout<<endl;
	}
	return 0;
}
