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

int cur_level[12];
int max_level[12];
int a[12][12];
int cost[12][12];
int n , m;
int increased_power , cost_incurred;
int power;

void solve(int s , int cost_incurred_curr , int increased_power_curr )
{
    if(s==n+1)
    {
        increased_power = max( increased_power_curr , increased_power );
        return;
    }
    forr(j,cur_level[s],max_level[s]-1)
    {
        solve(s+1,cost_incurred_curr,increased_power_curr);

        if( cost[s][j] + cost_incurred_curr <= m )
            increased_power_curr += a[s][j+1] - a[s][j] , cost_incurred_curr += cost[s][j] ;
        else 
            break;
    }
    solve(s+1,cost_incurred_curr,increased_power_curr);
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int T;
    cin >> T; 
    forr(t,1,T)
    {
    	cin >> m >> n ;
        power = 0;
        forr(i,1,n)
        {
            cin >> max_level[i] >> cur_level[i];
            forr(j,1,max_level[i])
            {
                cin >> a[i][j] ;
                if(j==cur_level[i]) power += a[i][j] ;
            }   
            forr(j,1,max_level[i]-1)    cin >> cost[i][j];
        }

        increased_power = 0;
        solve(1 , 0 , 0 );
        cout << "Case #" <<t<<": " << power + increased_power <<"\n";
    }
    return 0;
}