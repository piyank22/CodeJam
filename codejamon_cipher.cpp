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
#define ten9 1000000000
#define mod 1000000007
using namespace std;

map<string,int> m;

ll dp[4010];

int main()
{
    int t;
    scanf("%d",&t);
    forr(T,1,t)
    {
        m.clear();
        setzero(dp);

        int vocb,query;
        scanf("%d%d",&vocb,&query);
        forr(i,1,vocb)
        {
            string s;
            cin>>s;
            sort(s.begin(),s.end());
            m[s]++;
        }
        printf("Case #%d: ",T);
        forr(q,1,query)
        {
            char s[4010];
            scanf("%s",s+1);
            dp[0]=1;
            int leng = strlen(s)-1;
            forr(i,1,leng)
            {
                dp[i]=0;
                string t;
                rof(j,i,max(1,i-21))
                {
                    t += s[j];
                    sort(t.begin(),t.end());
                    if(m.find(t)!=m.end())
                        dp[i] = (dp[i] + dp[j-1]*m[t]%mod )%mod;
                }
            }
            cout<<(dp[leng]+mod)%mod<<" ";
        }
        cout<<endl;
    }
    return 0;
}
