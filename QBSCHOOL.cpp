#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;

#define INF 1e9

vector<vii> adjlist;
priority_queue<ii,vector<ii>,greater<ii> > pq;
ll cnt[5010];
ll dist[5010];

int main(){
    ll n,m,k,u,v,l;
    cin>>n>>m;


    for(ll i=1;i<=n;i++) dist[i]=INF;

    adjlist.assign(n+1,vii());
    cnt[1]=1;
    dist[1]=0;

    for(ll i=1;i<=m;++i) {
        cin >> k >> u >> v >> l;
        adjlist[u].push_back(ii(v,l));
        if(k == 2) {
            adjlist[v].push_back(ii(u,l));
        }
    }

    pq.push(ii(0,1));

    while(!pq.empty()){
        ii front=pq.top();
        pq.pop();
        ll d=front.first;
        ll u=front.second;

        if(d==dist[u]){
            for(ll i=0;i<adjlist[u].size();i++){
                ii v=adjlist[u][i];

                if(d+v.second<dist[v.first]){
                    dist[v.first]=d+v.second;
                    pq.push(ii(dist[v.first],v.first));

                    cnt[v.first]=cnt[u];
                }
                else if((d+v.second)==dist[v.first]){
                    cnt[v.first]+=cnt[u];
                }
            }

        }

    }

    cout<<dist[n]<<" "<<cnt[n];

}

