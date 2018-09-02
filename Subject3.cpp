#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=110000;
int a[maxn],b[maxn];
int n,p=0,q=0,k=0,g=0;
int main(){
    scanf("%d",&n);
    getchar();
    for(int i=1;i<=n;i++){
        char c;
        scanf("%c",&c);
        a[i]=int(c-'0');
    }
    getchar();
    for(int i=1;i<=n;i++){
        char c;
        scanf("%c",&c);
        b[i]=int(c-'0');
    }
    for(int i=1;i<=n;i++){
        if(a[i]==0 && b[i]==0)p++;
        if(a[i]==1 && b[i]==0)q++;
        if(a[i]==0 && b[i]==1)k++;
        if(a[i]==1 && b[i]==1)g++;
    }
    long long ans=(long long)(p*q+p*g+q*k);
    cout<<ans<<endl;
    return 0;
}