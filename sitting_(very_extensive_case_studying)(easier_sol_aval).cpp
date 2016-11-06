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

int main()
{
    int t;
    scanf("%d",&t);
    forr(T,1,t)
    {
        int _n,_m;
        cin >> _n >> _m;
        ll ans = 0;
        int n,m;
        n = min(_n,_m);
        m = max(_n,_m);
        if(n==1)
            ans = 2*(m/3) + m%3;
        else if(n==2)
            ans = 4*(m/3) + 2*(m%3);
        else
        {
            if(n%3==0 || m%3==0)
            {
                if(n%3!=0)  swap(n,m);
                ans = 2*m*n/3;
            }
            else if(n%3==1 && m%3==1)
            {
                ans = 1 + 2*m*(n/3) + 2*(m-1)/3;
            }
            else if(n%3==2 && m%3==2)
            {
                ans = 3 + 2*m*(n/3) + 4*(m-2)/3;
            }
            else
            {
                if(m%3!=1)  swap(n,m);
                ans = 2 + 2*m*(n/3) + 4*(m-1)/3;
            }
        }
        printf("Case #%d: %I64d\n",T,ans);
    }
    return 0;
}
