#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
long long b,p,mod;
long long powr(long long f,long long x){
    long long ret=1;
    while(x){
        if(x%2)ret=(ret*f)%mod;
        f=(f*f)%mod;
        x=x>>1;
    }
    return ret%mod;
}
int main(){
    scanf("%lld%lld%lld",&b,&p,&mod);
    printf("%lld^%lld mod %lld=%lld\n",b,p,mod,powr(b,p));
    //system("pause");
}
