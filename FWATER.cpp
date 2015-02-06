#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll,ii> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;

#define INF 1<<29
#define X first
#define Y second
#define ff(i,a,b) for(ll i=a;i<=b;++i)
#define FF(i,a,b) for(ll i=a;i>=b;--i)
#define N_ 1002

vector<vii> adjlist;
vector<bool> taken;
priority_queue<ii> pq;

void prim_process(int u){
	taken[u]=true;
	for(int i=0;i<adjlist[u].size();i++){
		ii v=adjlist[u][i];
		if(!taken[v.first]) pq.push(ii(-v.second,v.first));
	}
}

int main(){
	ll n,w,mst_cost=0;
	cin>>n;
	adjlist.assign(n+2,vii());
	taken.assign(n+2,false);
	
	for(int i=1;i<=n;i++){
		cin>>w;
		adjlist[i].push_back(ii(n+1,w));
		adjlist[n+1].push_back(ii(i,w));
	}
	
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
		cin>>w;
		if(i!=j) adjlist[i].push_back(ii(j,w));
	}
	
	prim_process(1);
	
	while(!pq.empty()){
		ii front=pq.top();
		pq.pop();
		
		ll u=front.second;
		ll d=-front.first;
		
		if(!taken[u]){
			mst_cost+=d;
			prim_process(u);
		}
	}
	
	cout<<mst_cost;
	
}
