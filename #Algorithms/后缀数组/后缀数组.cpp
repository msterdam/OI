#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=1.1e6;
char s[maxn];
int rank[maxn],sa[maxn];
int tp[maxn],tax[maxn];
int n,m;
int a[maxn];
void qsort(){
    for(int i=0;i<=m;i++)tax[i]=0;
    for(int i=1;i<=n;i++)tax[rank[tp[i]]]++;
    for(int i=1;i<=m;i++)tax[i]+=tax[i-1];
    for(int i=n;i>=1;i--)sa[tax[rank[tp[i]]]--]=tp[i];
}
void suffixsort(){
    for(int i=1;i<=n;i++)rank[i]=(int)s[i],tp[i]=i;
    qsort();
    for(int k=1;k<=n;k<<=1){
        int num=0;
        for(int i=n-k+1;i<=n;i++)tp[++num]=i;
        for(int i=1;i<=n;i++)if(sa[i]>k)tp[++num]=sa[i]-k;
        qsort();
        /*
        for(int i=1;i<=n;i++) printf("%d ",sa[i]);printf("\n");
        for(int i=1;i<=n;i++) printf("%d ",tp[i]);printf("\n");
        for(int i=1;i<=n;i++) printf("%d ",rank[i]);printf("\n\n");
        */
        swap(rank,tp);
        rank[sa[1]]=1;
        num=1;
        rank[sa[1]]=1;
        for(int i=2;i<=n;i++)
            rank[sa[i]]=(tp[sa[i]]==tp[sa[i-1]] && tp[sa[i]+k]==tp[sa[i-1]+k])?num:++num;
        if(num==n)break;
        m=num;	 
    }
}
int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    m=122;
    suffixsort();
    for(int i=1;i<=n;i++)printf("%d ",sa[i]);
    printf("\n");
    return 0;
}