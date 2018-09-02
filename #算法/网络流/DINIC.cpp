#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct edge{
    int v,f;
    edge *next,*rev;
}pool[100000],*head[1000];
const int inf=1<<30;
int n,m,lev[1000];
int top=0;
void add(int u,int v,int f){
    edge *temp1=&pool[top++];temp1->v=v;temp1->f=f;temp1->next=head[u];head[u]=temp1;
    edge *temp2=&pool[top++];temp2->v=u;temp2->f=0;temp2->next=head[v];head[v]=temp2;
    temp1->rev=temp2;
    temp2->rev=temp1;
}
bool bfs(){
    queue<int>que;
    for(int i=1;i<=n;i++)lev[i]=-1;
    lev[1]=0;
    que.push(1);
    while(!que.empty()){
        for(edge *temp=head[que.front()];temp;temp=temp->next){
            if(lev[temp->v]!=-1 || temp->f<=0)continue;
            lev[temp->v]=lev[que.front()]+1;
            que.push(temp->v);
            if(temp->v==n)return true;
        }
        que.pop();
    }
    return false;
}
int find(int s,int neck){
    if(s==n)return neck;
    int x=0,tot=0;
    for(edge *temp=head[s];temp;temp=temp->next){
        if(lev[temp->v]==lev[s]+1 && temp->f>0 && neck-tot>0){
            x=find(temp->v,min(neck-tot,temp->f));
            temp->f-=x;
            temp->rev->f+=x;
            tot+=x;
        }
    }
    if(tot==0)lev[s]=-1;
    return tot;
}
void dinic(){
    int ans=0;
    while(true){
        if(!bfs())break;
        ans+=find(1,inf);
    }
    printf("%d\n",ans);
}
int main(){
    while(scanf("%d%d",&m,&n)!=EOF){
        for(int i=0;i<=top;i++){
            pool[i].v=pool[i].f=0;
            pool[i].next=pool[i].rev=NULL;
        }
        for(int i=1;i<=n;i++)head[i]=NULL;
        top=0;
        for(int i=1;i<=m;i++){
            int u,v,f;
            scanf("%d%d%d",&u,&v,&f);
            add(u,v,f);
        }
        dinic();
    }
    return 0;
}