#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long n,k;
const long long mod=1000000007;
struct matrix{
    long long map[110][110];
    matrix operator*(matrix b){
        matrix c;
        for(long long i=1;i<=n;i++)
            for(long long j=1;j<=n;j++)
                c.map[i][j]=0;
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=n;j++){
                for(long long k=1;k<=n;k++){
                    c.map[i][j]=(c.map[i][j]+this->map[i][k]*b.map[k][j])%mod;
                }
            }
        }
        return c;
    }
}a,ret;
void powr(long long x){
    for(long long i=1;i<=n;i++){
        ret.map[i][i]=1;
    }
    while(x){
        if(x%2)ret=ret*a;
        a=a*a;
        x=x>>1;
    }
}
int main(){
    scanf("%lld%lld",&n,&k);
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){
            scanf("%lld",&a.map[i][j]);
        }
    }
    powr(k);
    a=a*a;
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){
            printf("%lld ",ret.map[i][j]);
        }
        printf("\n");
    }
    //system("pause");
    return 0;
    }