#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const long long maxv=10010,maxn=10010;
long long n,m,V;
long long dp[maxv];
inline long long read() {
    char ch = getchar(); long long x = 0, f = 1;
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    } while('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    } return x * f;
}
int main(){
    n=read();
    m=read();
    V=read();
    for(long long i=1;i<=n;i++){
        long long cost,value,cnt;
        cost=read();
        value=read();
        cnt=read();
        if(cnt*cost>V){
            for(long long j=cost;j<=V;j++){
                dp[j]=max(dp[j],dp[j-cost]+value);
            }
        }
        else{
            for(long long k=1;k<=cnt;k*=2){
                for(long long j=V;j>=cost*k;j--){
                    dp[j]=max(dp[j],dp[j-k*cost]+k*value);
                }
                cnt-=k;
            }
            if(cnt>0){
                for(long long j=V;j>=cost*cnt;j--){
                    dp[j]=max(dp[j],dp[j-cnt*cost]+cnt*value);
                }
            }
        }
    }
    for(long long i=1;i<=m;i++){
        long long a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        for(long long j=V;j>=0;j--){
            for(long long k=0;k<=j;k++){
                dp[j]=max(dp[j],dp[j-k]+a*k*k+b*k+c);
            }
        }
    }
    printf("%lld\n",dp[V]);
    //system("pause");
    return 0;
}