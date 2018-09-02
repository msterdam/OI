#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
const int MAXN=200010;
struct node{
    int d;
	int size,rnd;
    int ch[2];
}p[MAXN];
int top=0;
int n,root;
int newnode(int v)
{
    top++;
    p[top].d=v;
    p[top].size=1;
    p[top].rnd=rand();
    return top;
}
int size(int x)
{
    if(x>0 && x<MAXN)return p[x].size;
    return 0;
}
void update(int x)
{
    p[x].size=size(p[x].ch[0])+size(p[x].ch[1])+1;
}
void split(int now,int k,int &x,int &y)
{
    if(now==0){
	    x=y=0;
	    return;
	}
    if(p[now].d<=k)
		x=now, split(p[now].ch[1],k,p[now].ch[1],y);
	else
	    y=now, split(p[now].ch[0],k,x,p[now].ch[0]);
	update(now);
}
int merge(int x,int y)
{
    if(x==0 || y==0)return x+y;
    if(p[x].rnd<p[y].rnd){
	    p[x].ch[1]=merge(p[x].ch[1],y);
	    update(x);
	    return x;
	}
    else{
	    p[y].ch[0]=merge(x,p[y].ch[0]);
	    update(y);
	    return y;
	}
}
int kth(int now,int k)
{
     while(true){
	     if(k<=size(p[now].ch[0]))now=p[now].ch[0];
	     else if(k==size(p[now].ch[0])+1)return now;
	     else k-=size(p[now].ch[0])+1,now=p[now].ch[1];
	 }
}
void insert(int v)
{
	int x,y;
    split(root,v,x,y);
    root=merge(merge(x,newnode(v)),y);
}
void del(int v)
{
    int x,y,z;
    split(root,v,x,z);
    split(x,v-1,x,y);
    y=merge(p[y].ch[0],p[y].ch[1]);
    root=merge(merge(x,y),z);
}
int Qkth(int v)
{
	int x,y;
    split(root,v-1,x,y);
    int ret=size(x)+1;
    root=merge(x,y);
    return ret;
}
int pre(int v)
{
	int x,y;
    split(root,v-1,x,y);
    int ret=kth(x,size(x));
    root=merge(x,y);
    return ret;
}
int next(int v)
{
	int x,y;
    split(root,v,x,y);
    int ret=kth(y,1);
    root=merge(x,y);
    return ret;
}
void inorder(int x)
{
    if(x==0)return;
    inorder(p[x].ch[0]);
    printf("%d ",p[x].d);
    inorder(p[x].ch[1]);
}
int main()
{
	srand(time(NULL));
	scanf("%d",&n);
	root=0;
	p[0].ch[0]=p[0].ch[1]=1;
	for(int i=1;i<=n;i++){
	    int q,a;
	    scanf("%d%d",&q,&a);
	    switch (q){
		    case 1:insert(a);break;
		    case 2:del(a);break;
		    case 3:printf("%d\n",Qkth(a));break;
		    case 4:printf("%d\n",p[kth(root,a)].d);break;
		    case 5:printf("%d\n",p[pre(a)].d);break;
		    case 6:printf("%d\n",p[next(a)].d);break;
	    }
	}
    return 0;
}
