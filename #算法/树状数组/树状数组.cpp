#include <iostream>
#include <cstdio>
using namespace std;
int n,m;
int a[500005];
long long int bit[500005];
int ans[500005];
int cnt=0;
int lowbit(int x)
{
    return x&(-x);    
}
void add(int x,int k)
{
    for(;x<=n;x+=lowbit(x))
        bit[x]+=k;    
}
int query(int x)
{
    int ans=0;
    for(;x;x-=lowbit(x))
        ans+=bit[x];
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);   
        add(i,a[i]);    
    }
    for(int i=1;i<=m;i++)
    {
        int q,c,b;
        scanf("%d",&q);
        if(q==1)
        {
            scanf("%d%d",&c,&b);
            add(c,b);   
        }        
        if(q==2)
        {
            scanf("%d%d",&c,&b);
            printf("%d\n",query(b)-query(c-1));
        }
    }
    system("pause");
    return 0;    
}
