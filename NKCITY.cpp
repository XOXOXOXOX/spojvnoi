#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;

#define pb push_back
#define INF 1e9
#define X first
#define Y second
#define ff(i,a,b) for(ll i=a;i<=b;++i)
#define FF(i,a,b) for(ll i=a;i>=b;--i)
#define f0(i,n) for(ll i=0;i<n;++i)
#define f_all(i,a) for(ll i=0;i<a.size();++i)
#define N_ 1002
#define all(a) a.begin(),a.end()

/// union-find disjoint-set

vi pset;
void init(int n){
    pset.assign(n+1,0);
    ff(i,1,n) pset[i]=i;
}

ll findset(ll x){
    if(x==pset[x]) return x;
    else return pset[x]=findset(pset[x]);
}
bool issameset(ll x,ll y){
    return findset(x)==findset(y);
}
void unionset(ll x,ll y){
    ll rx=findset(x);
    ll ry=findset(y);
    pset[rx]=ry;
}

ll n,m,res;
vector<iii> edge;


int main(){
    ios_base::sync_with_stdio(false);
    ll u,v,w;

    cin>>n>>m;
    init(n);
    f0(i,m){
        cin>>u>>v>>w;
        edge.pb(iii(w,ii(u,v)));
    }

    /// Kruskal:
    res=0;
    sort(all(edge));

    f_all(i,edge){
        w=edge[i].X;
        u=edge[i].Y.X;
        v=edge[i].Y.Y;

        if(!issameset(u,v)){
            res=max(res,w);
            unionset(u,v);
        }
    }

    cout<<res;

}
