#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <windows.h>
using namespace std;
long long n,m,k;
long long dp[5010][5000];
long long a[5010];
long long sum[5010];
long long getdp(long long x,long long y){
    if(x<1 || x>n || y<0 || y>k)return 0;
    if(x<m && y>0)return 1<<31;
    if(dp[x][y]!=-1)return dp[x][y];
    dp[x][y]=max(getdp(x-1,y),getdp(x-m,y-1)+sum[x]-sum[x-m]);
    return dp[x][y];
}
int main()
{
    memset(dp,-1,sizeof(dp));
    memset(sum,0,sizeof(sum));
    cin>>n>>m>>k;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        dp[i][0]=0;
    }
    long long ans=getdp(n,k);
    cout<<ans<<endl;
    //system("pause");
    return 0;
}