#include <iostream>
#include <set>
#include <algorithm>
#include <cstdio>

using namespace std;

set<string> count_set[28] ;
set<char> s;

int main() {
	// your code goes here
	int t;
	cin>>t;
	for(int T=1;T<=t;T++)
	{
		for(int i=0;i<27;i++)	count_set[i].clear();
		int n;
		cin >> n;
		cin.ignore();
		while(n--)
		{
			string temp;
			getline(cin,temp);
			s.clear();
			for(int i=0;i<temp.size();i++)
			{
				if(temp[i]==' ')continue;
				s.insert(temp[i]);
			}
			count_set[s.size()].insert(temp);
		}
		string ans;
		for(int i=26;i>=1;i--)
		{
			if(count_set[i].size()!=0)
			{
				ans = *count_set[i].begin();
				break;
			}
		}
		printf("Case #%d: ",T);
		cout<<ans<<endl;
	}
	return 0;
}
