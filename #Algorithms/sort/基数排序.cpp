#include <iostream>
#include <cstdio>
using namespace std;
int n;
int a[100005],b[100005];
int s[100005];
int cnt[1<<17];
int p=(1<<16)-1;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)cnt[a[i]&p]++;
    for(int i=1;i<=p;i++)cnt[i]+=cnt[i-1];
    for(int i=n;i>=1;i--)b[cnt[a[i]&p]--]=a[i];
    for(int i=0;i<=p;i++)cnt[i]=0;
    for(int i=1;i<=n;i++)cnt[b[i]>>16]++;
    for(int i=1;i<=p;i++)cnt[i]+=cnt[i-1];
    for(int i=n;i>=1;i--)a[cnt[(b[i]>>16)&p]--]=b[i];
    for(int i=1;i<=n;i++)printf("%d ",a[i]);
    getchar();
    getchar();
    return 0;
}