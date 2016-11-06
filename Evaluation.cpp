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
#define eps 1e-5
#define forr(i,a,b) for(int i = int(a) ; i<= int(b) ; i++ )
#define rof(i,a,b)  for(int i = int(a) ; i>= int(b) ; i-- )

using namespace std;

bool solve( map< string , set<string> > &m )
{
	map< string , set<string> >::iterator it;
	stack< string > st;

	for(it=m.begin();it!=m.end();it++)
		if( (it->second).empty() == true )
		{
			st.push( it->first ) ;
		}

	while(!st.empty())
	{
		string s = st.top() ;
		st.pop();
		m.erase(s);
		for(it=m.begin();it!=m.end();it++)
		{
			(it->second).erase(s);
			if( (it->second).empty() == true )
				st.push(it->first);
		}
	}
	if(m.empty())
		return true;
	else
		return false;
}

int main()
{
	int t;
	cin>>t;
	map< string , set<string> > m;
	set< string > s1,s2 ;
	bool ans;
	forr(k,1,t)
	{
		ans=true;

		s1.clear();
		s2.clear();
		m.clear();
		
		int n;
		cin>>n;
		
		while(n--)
		{
			string s;
			cin>>s;

			forr(i,0,s.size()-1)
				if(s[i]==',' || s[i]==')' || s[i]=='(' || s[i]=='=' )
					s[i]=' ';

			stringstream ss(s);
			ss>>s;

			m[s]=set<string>();
			s1.insert(s);
			string garbage;
			ss>>garbage;

			string t;
			while(ss>>t)
			{
				m[s].insert(t);
				s2.insert(t);
			}

			if( m[s].find(s)!=m[s].end() )
			 	ans=false;
		}

		for(set< string >::iterator it=s2.begin();it!=s2.end();it++)
			if(s1.find(*it)==s1.end())
			{
				ans = false ;
				break ;
			}

		if(ans)// only remains to check if it has a cycle or not
			ans=solve(m);
		printf("Case #%d: ",k );
		if(ans)
			cout<<"GOOD\n";
		else
			cout<<"BAD\n";
	}
	return 0;
}