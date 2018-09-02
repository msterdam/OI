#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=110000;
int ans[maxn],n,x;
int main(){
    scanf("%d",&n);
    x=sqrt(n);
    int last=n;
    while(last>=1){
        for(int i=max(1,last-x+1);i<=last;i++){
            printf("%d ",i);
        }
        last-=x;
    }
    //system("pause");
    return 0;
}