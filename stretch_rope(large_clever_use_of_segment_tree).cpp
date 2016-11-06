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
using namespace std;
ll arr[10001];
ll seg_tree[10001<<2];

void build_seg_tree(int pos,int l,int r)
{
    if(l==r)
    {
        seg_tree[pos] = arr[l];
        return;
    }
    int mid = (l+r)>>1;
    build_seg_tree(2*pos+1,l,mid);
    build_seg_tree(2*pos+2,mid+1,r);
    seg_tree[pos] = min( seg_tree[2*pos+1] , seg_tree[2*pos+2] );
}

ll get_res(int pos , int st,int en,int l, int r)
{
    if(en<l || r<st)
        return 1e15;
    if(st<=l && r<=en)
        return seg_tree[pos];
    int mid = (l+r)>>1;
    return min( get_res(2*pos+1,st,en,l,mid) , get_res(2*pos+2,st,en,mid+1,r) );
}
void update(int pos, int index, int l, int r, ll val)
{
    if(l==r)
    {
        seg_tree[pos] = min(val,seg_tree[pos]);
        return;
    }
    int mid=(l+r)>>1;
    if(index <= mid) update(2*pos+1,index,l,mid,val);
    else update(2*pos+2,index,mid+1,r,val);
    seg_tree[pos] = min( seg_tree[2*pos+1] , seg_tree[2*pos+2] );
}
int main()
{
    int t;
    scanf("%d",&t);
    forr(T,1,t)
    {
        int n,m,l;
        scanf("%d%d%d",&n,&m,&l);
        forr(i,1,l)
            arr[i]=1e15;
        arr[0]=0;
        build_seg_tree(0,0,l);

        forr(i,1,n)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if(b>=l) b=l;
            rof(j,l,1)
            {
                int st = j - b;
                int en = j - a;
                if(st<0)
                    st=0;
                if(en<0)
                    break;
                if(en==j)
                    en--;
                ll min_val_in_range = get_res(0,st,en,0,l);
                if( arr[j] > min_val_in_range + c )
                {
                    arr[j] = min_val_in_range + c;
                    update(0,j,0,l,arr[j]);
                }
            }
        }
        
        printf("Case #%d: ",T);
        if(arr[l]>m)
            printf("IMPOSSIBLE\n");
        else
            cout<<arr[l]<<endl;
    }
    return 0;
}
