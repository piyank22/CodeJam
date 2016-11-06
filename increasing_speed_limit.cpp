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
#define mod  1000000007
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

const int max_n = 5e5+50;
//const int mod = 1e9+7;

ll a[max_n];
ll s[max_n];
ll ss[max_n];
ll fen_tree[max_n];

#define lsone(i) (i)&(-i)
void up_fen_tree(int pos, ll val )
{
    for(int i = pos; i>0; i -= lsone(i) )    fen_tree[i] = (fen_tree[i]+val)%mod ;
}

ll get_fen_tree(int pos)
{
    ll res=0;
    for(int i = pos ; i<max_n; i += lsone(i) )
        res = ( res + fen_tree[i] )%mod;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    forr(t,1,T)
    {
        ll n,m,x,y,z;
        cin >> n >> m >> x >> y >> z;
        forr(i,0,m-1)
            cin >> a[i];

        forr(i,0,n-1)
        {
            s[i] = a[i%m];
            a[i%m] = ( x*a[i%m]%z + y*(i+1)%z )%z; 
        }

        ll ans = 0;
        zero(fen_tree);
        memcpy(ss,s,sizeof(s));
        sort(ss,ss+n);
        forr(i,0,n-1)
            s[i] = lower_bound(ss,ss+n,s[i])-ss+1;

        rof(i,n-1,0)
        {
            ll res = 1+get_fen_tree(s[i]+1);
            up_fen_tree(s[i],res);
            ans = (ans+res)%mod ;
        }

        cout << "Case #" <<t<<": "<<ans<<"\n";
    }

    return 0;
}