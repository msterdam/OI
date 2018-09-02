#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1.1e6;
char a[maxn],b[maxn];
int next[maxn],lena,lenb;
int ans=0;
int main(){
    scanf("%s%s",a+1,b+1);
    lena=strlen(a+1);
    lenb=strlen(b+1);
    int j=0;
    next[1]=0;next[0]=0;
    for(int i=2;i<=lenb;i++){
        while(j && b[j+1]!=b[i])j=next[j];
        if(b[j+1]==b[i])j++;
        next[i]=j;
    }
    j=0;
    for(int i=1;i<=lena;i++){
        while(j && b[j+1]!=a[i])j=next[j];
        if(b[j+1]==a[i])j++;
        if(j==lenb){
            ans++;
            printf("%d\n",i-lenb+1);
            j=next[j];
        }
    }
    for(int i=1;i<=lenb;i++){
        printf("%d ",next[i]);
    }
    return 0;
}