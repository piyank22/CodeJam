#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <sstream>
#include <cassert>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <vector>

#define PI acos(-1)
#define endl '\n'
#define ll long long
#define llu long long unsigned
#define pii pair<int,int>
#define vi vector<int>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define sz(v) int(v.size())
#define eps 1e-5
#define zero(a) memset(a,0,sizeof(a))
#define minus(a) memset(a,0xff,sizeof(a))
#define forr(i,a,b) for(int i = int(a) ; i<= int(b) ; i++ )
#define rof(i,a,b)  for(int i = int(a) ; i>= int(b) ; i-- )
#define rep(i,n) for(int i=0 ; i<int(n) ; i++ )
#define INF 0x3fffffff
#define ten9 1000000000
// #define mod  1000000007
#define trace1(x) cerr<<#x<<" = "<<x<<endl;
#define trace2(x,y) cerr<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<endl;
#define trace3(x,y,z) cerr<<#x<<" = "<<x<<" , "<<#y<<" = "<<y<<" , "<<#z<<" = "<<z<<endl;

using namespace std;

template<class T, class U>
ostream& operator<<(ostream& out, const pair<T, U>& a) {out << "[" << a.first << " " << a.second << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const vector<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const set<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const multiset<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T, class U>
ostream& operator<<(ostream& out, const map<T, U>& a) {for (auto &it : a)out << it.first << " -> " << it.second << " | "; return out;}
template<class T, class U>
ostream& operator<<(ostream& out, const multimap<T, U>& a) {for (auto &it : a)out << it.first << " -> " << it.second << " | "; return out;}

string s;
#define mod (2*3*5*7)

ll ans=0;
ll dp[50][300]; // dp[41][210] // dp[i][j] = total number of poss of getting string from 0 - i having mod val j

void solve()
{
    forr(i,0,sz(s)-1)
    {
        int curr = 0;
        forr(j,i,sz(s)-1) // you are placing a sign before the jth pos // when j=0 you are not permitted to place a minus sign before it
        {
            curr = (curr*10 + s[j] - '0') % mod ; // string from i to j has mod curr
            forr(x,0,mod-1)
            {
                dp[j+1][(x+mod+(+1)*curr)%mod] += dp[i][x];
                if(i>0)     dp[j+1][(x+mod+(-1)*curr)%mod] += dp[i][x];
            }
        }
    }

    forr(i,0,mod-1)
        ans += ( ( i%2==0 || i%3==0 || i%5==0 || i%7==0 ) ? dp[sz(s)][i] : 0 );
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    forr(t,1,T)
    {
        zero(dp);
        dp[0][0]=1;
        ans=0;
        cin >> s;
        solve();
        cout << "Case #" <<t<<": "<<ans<<"\n";
    }

    return 0;
}