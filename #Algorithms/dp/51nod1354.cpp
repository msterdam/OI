#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
map<int,int> m[1100];
map<int,int>::iterator it;
const int maxn=1100;
const int mod=1000000007;
int T;
int a[maxn];
int n,k;
int getdp(int i,int j){
    if(i<0 || i>n)return 0;
    if(m[i][j]!=0)return m[i][j];
    if(j%a[i]!=0)return getdp(i-1,j);;
    return m[i][j]=(getdp(i-1,j/a[i])+getdp(i-1,j))%mod;
}
int main(){
    cin>>T;
    for(int t=1;t<=T;t++){
        scanf("%d%d",&n,&k);
        a[0]=1;      
        for(int i=1;i<=n;i++){
            m[i].clear();
            scanf("%d",&a[i]);
        }
        m[0][1]=1;
        int ans=1;
        ans=getdp(n,k);
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}
