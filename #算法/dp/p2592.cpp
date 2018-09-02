#include <cstdio>
#include <algorithm>
using namespace std;
const int mod=12345678;
const int maxn=160,maxk=24;
int n,m,k;
int dp[maxn][maxn][maxk][maxk];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    dp[0][0][0][0]=1;
    for(int i=0;i<=n+m;i++){
        for(int j=0;j<=n;j++){
            for(int x=0;x<=k;x++){
                for(int y=0;y<=k;y++){
                    if(j+1<=n && x+1<=k)(dp[i+1][j+1][x+1][max(0,y-1)]+=dp[i][j][x][y])%=mod;
                    if(i-j+1<=m && y+1<=k)(dp[i+1][j][max(0,x-1)][y+1]+=dp[i][j][x][y])%=mod;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<=k;i++){
        for(int j=0;j<=k;j++){
            (ans+=dp[n+m][n][i][j])%=mod;
        }
    }
    printf("%d\n",ans);
    system("pause");
    return 0;
}