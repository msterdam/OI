#include <cstdio>
#include <algorithm>
using namespace std;
long long gcd(long long a,long long b){
    if(b==0)return a;
    return (b,a%b);
}
long long exgcd(long long a,long long b,long long &x,long long &y){
    if(b==0){
        x=1;y=0;
        return a;
    }
    long long ret=exgcd(b,a%b,x,y);
    long long x2=x,y2=y;
    x=y2;
    y=x2-(a/b)*y2;
    return ret;
}
int main(){
    long long a,b;
    scanf("%lld%lld",&a,&b);
    long long x,y,g;
    g=exgcd(a,b,x,y);
    printf("%lld\n",(x+b)%b);
    system("pause");
    return 0;
}