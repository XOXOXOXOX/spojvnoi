#include<stdio.h>

long n,i,j,b[20][20],a[20][20],mini=200,one[20],t,k,cost;
char c[20];
bool now;

int main(){
    scanf("%ld",&n);
    now=false;
    for(i=1;i<=n;i++){
        scanf("%s",c);
        for(j=0;j<n;j++){
            if(c[j]=='0') b[i][j+1]=0;
            else b[i][j+1]=1;
        }
    }

    if(n==1) printf("0\n");
    else{
        KK:;
        for(k=0;k<=(1<<n)-1;k++){
            for(t=1;t<=n;t++)
            for(j=1;j<=n;j++) a[t][j]=b[t][j];

            cost=0;
            for(t=0;t<n;t++){
                if(k&1<<(n-t-1)){
                    cost++;
                    a[1][t+1]=1-a[1][t+1];
                    if(t-1>=0) a[1][t]=1-a[1][t];
                    if(t+1<n) a[1][t+2]=1-a[1][t+2];
                    a[2][t+1]=1-a[2][t+1];
                }
            }

            for(i=2;i<=n;i++){
                for(j=1;j<=n;j++){
                    if(a[i-1][j]==0){
                        one[j]=1;
                        cost++;
                    }
                    else one[j]=0;
                }

                for(j=1;j<=n;j++){
                    if(one[j]==1){
                        a[i][j]=1-a[i][j];
                        if(j-1>0) a[i][j-1]=1-a[i][j-1];
                        if(j+1<=n) a[i][j+1]=1-a[i][j+1];
                        if(i<n) a[i+1][j]=1-a[i+1][j];
                    }
                }
                if(i==n){
                    bool have=false;
                    for(j=1;j<=n;j++){
                        if(a[n][j]==0){
                            have=true;
                            break;
                        }
                    }

                    if(have) cost=2000;
                    else if(cost<mini){
                        mini=cost;

                    }
                }
            }

        }
        if(!now){
            now=true;
            for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            b[i][j]=1-b[i][j];
            goto KK;
        }

        if(mini>=200) printf("-1\n");
        else printf("%ld\n",mini);
    }
}

