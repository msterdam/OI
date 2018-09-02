#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
long long a[13];
long long f[13];
long long m;
int main(){
    for(long long i=1;i<=10;i++)
        f[i]=i*pow(10,i-1);
    long long num;
    cin>>num;
    m=num;
    for(long long i=10;i>=1;i--){
        long long t=pow(10,i-1);
        a[i]=num/t;
        num%=t;
    }
    long long ans=0;
    for(long long i=10;i>=1;i--){
        for(long long j=0;j<=a[i];j++){
            if(j!=a[i])ans+=f[i-1];
            if(j==1 && a[i]!=1){
                ans+=pow(10,i-1);
            }
            if(j==1 && a[i]==1){
                ans+=m%int(pow(10,i-1))+1;
            }
            if(j==a[i])continue;
        }
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}