#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9

vector<vii> adjlist;
priority_queue<ii> pq;
vector<bool> taken;

void primproc(int u){
    taken[u]=true;
    for(int i=0;i<adjlist[u].size();i++){
        ii v=adjlist[u][i];
        if(!taken[v.first])
        pq.push(ii(-v.second,v.first));
    }
}

int main(){
    int n,m,u,v,l;
    int mst_cost=0;
    cin>>n>>m;

    taken.assign(n+1,false);
    adjlist.assign(n+1,vii());

    for(ll i=1;i<=m;++i) {
        cin >> u >> v >> l;
        adjlist[u].push_back(ii(v,l));
        adjlist[v].push_back(ii(u,l));

    }

    primproc(1);

    while(!pq.empty()){
        ii front=pq.top();
        pq.pop();

        int u=front.second;
        int c=-front.first;

        if(!taken[u]){
            mst_cost+=c;
            primproc(u);
        }
    }

    cout<<mst_cost;

}

