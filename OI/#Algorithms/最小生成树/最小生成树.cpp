#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=7010,maxm=300010;
int n,m;
int ans=0,cnt=0;
struct edge{int u,v,c;}e[maxm];
int f[maxn];
int find(int x){
    if(f[x]==x)return x;
    return f[x]=find(f[x]);
}
bool cmp(edge a,edge b){
    return a.c<=b.c;
}
void kruskal(){
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=m;i++){
        int eu=find(e[i].u),ev=find(e[i].v);
        if(eu==ev)continue;
        ans+=e[i].c;
        f[ev]=eu;
        cnt++;
        if(cnt==n-1)return;
    }
    ans=-1;
}
int main(){
    for(int i=0;i<maxn;i++)f[i]=i;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].c);
    }
    kruskal();
    if(ans==-1)printf("orz\n");
    else printf("%d\n",ans);
    system("pause");
    return 0;
}