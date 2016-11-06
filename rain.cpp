#include <iostream>
#include <iomanip>
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

int n,m;
int a[55][55];
int b[55][55];
int ans;
int cnt;

int id[55][55];

int parent[3500];
int size[3500];

int uf_find(int i)
{
    return ( parent[i]==i ? i : ( parent[i]=uf_find(parent[i]) ) );
}

void uf_merge(int i,int j)
{
    i=uf_find(i);
    j=uf_find(j);
    if(i!=j)
    {
        if(size[i]>size[j]) parent[j]=i , size[i] += size[j];
        else                parent[i]=j , size[j] += size[i];
    }
}

void solve(int hi)
{
    forr(i,0,3500)  parent[i]=i , size[i]=i;

    forr(i,0,n+1)
        forr(j,0,m+1)
        {
            if(j!=m+1 && b[i][j]<hi && b[i][j+1]<hi ) uf_merge( id[i][j] , id[i][j+1] );
            if(i!=n+1 && b[i][j]<hi && b[i+1][j]<hi ) uf_merge( id[i][j] , id[i+1][j] ); 
        }

    forr(i,1,n)
        forr(j,1,m)
            if(b[i][j]<hi && uf_find(id[i][j]) != uf_find(id[0][0]) )    b[i][j] = hi;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int T;
    cin >> T; 
    forr(t,1,T)
    {
        cin >> n >> m;
        zero(a) ; zero(b) ; ans=0;

        // initialization for disjoint set
        cnt=0;
        forr(i,0,n+1) forr(j,0,m+1) id[i][j] = cnt++ ;

        forr(i,1,n) forr(j,1,m) cin >> a[i][j] , b[i][j] = a[i][j] ;

        rof(j,1000,1)
            solve(j);

        forr(i,1,n) forr(j,1,m) ans += b[i][j] - a[i][j] ;

        printf("Case #%d: %d\n",t,ans );
    }
    return 0;
}