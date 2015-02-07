#include<bits/stdc++.h>
using namespace std;

#define N_ 1<<6

long long l,t,m,n,res;

int bit(int i,int j){
    return i&(1<<j);
}

bool check(int i,int j){
    for(int k=0;k<n-1;k++){
        if( bit(i,k) && bit(i,k+1) && bit(j,k) && bit(j,k+1) ) return false;
        if( !bit(i,k) && !bit(i,k+1) && !bit(j,k) && !bit(j,k+1) ) return false;
    }

    return true;
}

int main(){

    cin>>t;
    while(t--){
        cin>>n>>m;
        if(n>m) swap(n,m);

        long long l=1<<n;
        long long dp[N_][31]={0};
        res=0;

        for(int i=0;i<N_;i++) dp[i][1]=1;

        for(int c=2;c<=m;c++){
            for(int i=0;i<l;i++){
                for(int j=0;j<l;j++){
                    if(check(i,j)) dp[i][c]+=dp[j][c-1];
                }
            }
        }

        for(int i=0;i<l;i++) res+=dp[i][m];

        cout<<res<<endl;
    }

}

