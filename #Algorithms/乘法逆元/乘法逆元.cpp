#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=3100000;
int inv[maxn];
int mod,n;
void getinv(){//递推法
    inv[1]=1;
    for(int i=2;i<=min(mod-1,n);i++){//注意范围
        inv[i]=(long long)(mod-mod/i)*inv[mod%i]%mod;
    }
}
int power(int x,int f){//x^f
    int ret=1;
    while(f){
        if(f%2)ret=(ret*x)%mod;
        x=(x*x)%mod;
        f=f>>1;
    }
    return ret; 
}
int calinv(int x){
    return power(x,mod-2);
}
int main(){
    scanf("%d%d",&n,&mod);
    getinv();
    for(int i=1;i<=n;i++){
        printf("%d\n",inv[i%mod]);
    }
    system("pause");
    return 0;
}