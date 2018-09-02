#include <iostream>
#include <cstdio>
#define defm int mid=(left+right)/2
using namespace std;
const int MAXN=100005,INF=1000000000;
int n,m,siz[MAXN],son[MAXN],dep[MAXN],val[MAXN],top[MAXN],w[MAXN],d[MAXN],df,pnt[MAXN];
struct itree{
	itree *son[2];
	int Min;
}pool[3*MAXN],*root;
int cnt;
struct node{
	node *next;
	int v;
}npool[2*MAXN],*h[MAXN];
int ncnt;
void addedge(int u,int v){
	node *o=&npool[ncnt++];
	o->v=v,o->next=h[u],h[u]=o;
	o=&npool[ncnt++];
	o->v=u,o->next=h[v],h[v]=o;
}
void Change(itree *o,int left,int right,int pos,int d){
	if(left==right){o->Min=d;return;}
	defm;
	if(pos<=mid)Change(o->son[0],left,mid,pos,d);
	else Change(o->son[1],mid+1,right,pos,d);
	o->Min=min(o->son[0]->Min,o->son[1]->Min);
}
int Query(itree *o,int left,int right,int l,int r){
	if(l==left&&r==right)return o->Min;
	defm;
	if(r<=mid)return Query(o->son[0],left,mid,l,r);
	if(l>mid) return Query(o->son[1],mid+1,right,l,r);
	return min(Query(o->son[0],left,mid,l,mid),
			   Query(o->son[1],mid+1,right,mid+1,r));
}
itree *build(int left,int right){
	itree *o=&pool[cnt++];
	if(left==right){o->Min=val[left];return o;}
	defm;
	o->son[0]=build(left,mid);
	o->son[1]=build(mid+1,right);
	o->Min=min(o->son[0]->Min,o->son[1]->Min);
	return o;
}
void dfs1(int u){
	siz[u]=1;
	for(node *o=h[u];o;o=o->next)if(o->v!=pnt[u]){
		pnt[o->v]=u;
		dep[o->v]=dep[u]+1;
		dfs1(o->v);
		siz[u]+=siz[o->v];
		if(!son[u]||siz[o->v]>siz[son[u]])son[u]=o->v;
	}
}
void dfs2(int u){
	w[u]=++df,val[df]=d[u];
	if(son[u]){
		top[son[u]]=top[u];
		dfs2(son[u]);
	}
	for(node *o=h[u];o;o=o->next)if(o->v!=pnt[u]&&o->v!=son[u]){
		top[o->v]=o->v;
		dfs2(o->v);
	}
}
int Querytree(int u,int v){
	int ret=INF;
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		ret=min(ret,Query(root,1,n,w[top[u]],w[u]));
		u=pnt[top[u]];
	}
	if(dep[u]>dep[v])swap(u,v);
	ret=min(ret,Query(root,1,n,w[u],w[v]));
	return ret;
}
int main(){
	int typ,u,v;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&d[i]);
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		addedge(u,v);
	}
	dep[1]=1;
	dfs1(1);
	top[1]=1;
	dfs2(1);
	root=build(1,n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&typ,&u,&v);
		if(typ==1)Change(root,1,n,w[u],v);
		else{
			printf("%d\n",Querytree(u,v));
		}
	}
	return 0;
}
