#include <iostream>
using namespace std;
const int MAXN=150000;
int n,m,top;
struct Tree
{
    Tree *lson,*rson;
    long long sum,lazy;
    int l,r;
}pool[MAXN*4+300],*root;
void fa_lazy(Tree *node)
{
    if(node->lson) node->lson->lazy+=node->lazy;
    if(node->rson) node->rson->lazy+=node->lazy;
    node->sum+=node->lazy*(node->r-node->l+1);
    node->lazy=0;
}
void ud(Tree *node)
{
    if(node->lson) fa_lazy(node->lson);
    if(node->rson) fa_lazy(node->rson);
	node->sum=node->lson->sum+node->rson->sum;
}
void build(Tree *node,int l,int r)
{
    node->l=l;
    node->r=r;
    if(l==r)
    {
	    scanf("%d",&node->sum);
	    return;
	}
	node->lson=&pool[++top];
    node->rson=&pool[++top];
	int m=(l+r)/2;
	build(node->lson,l,m);
	build(node->rson,m+1,r);
	ud(node);
}
void change(Tree *node,int l,int r,int num)
{
    if(l==node->l&&r==node->r){node->lazy+=num;return;}
    fa_lazy(node);
    if(node->lson->r>=r)change(node->lson,l,r,num);
    else if(node->rson->l<=l)change(node->rson,l,r,num);
    else
    {
	    change(node->lson,l,node->lson->r,num);
	    change(node->rson,node->rson->l,r,num);
	}
	ud(node);
}
int query(Tree *node,int l,int r)
{
    if(l==node->l&&r==node->r){return node ->sum+node->lazy*(node->r-node->l+1);}
    fa_lazy(node);
    int  ans;
    if(node->lson->r>=r)ans=query(node->lson,l,r);
    else if(node->rson->l<=l)ans=query(node->rson,l,r);
    else
    {
	    ans=query(node->lson,l,node->lson->r)+
	        query(node->rson,node->rson->l,r);
	}
	return ans;
}
int main()
{
    root=&pool[0];
    build(root,1,n);
    system("pause");
    return 0;
}
