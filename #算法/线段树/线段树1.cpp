#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=400000;
struct segtree{
	int top;
    struct node{
        int lazy;
        int sum;
        int l,r;
        node *lson,*rson;
    }pool[maxn],*root;
    void addnode(node *&p,int l,int r){
        p=&pool[top++];
        p->l=l;p->r=r;
        p->lazy=0;p->sum=0;
    }
    segtree(void) {
        top=0;
    	addnode(root,0,100000);
    }
    void falazy(node *p){
        p->lson->lazy+=p->lazy;
        p->rson->lazy+=p->lazy;
        p->lson->sum+=p->lazy*(p->lson->r-p->lson->l+1);
        p->rson->sum+=p->lazy*(p->rson->r-p->rson->l+1);
        p->lazy=0;
    }
    void update(node *p){
        p->sum=p->lson->sum+p->rson->sum;
    }
    void change(node *p,int l,int r,int num){
    	//printf("%d %d %d %d\n",p->l,p->r,l,r);
    	//system("pause");
        if(l>r)return;
        if(p->l==l && p->r==r){
            p->lazy+=num;
            p->sum+=num*(p->r-p->l+1);
            return;
        }
        if(!p->lson || !p->rson){
            int mid=(p->l+p->r)/2;
            addnode(p->lson,p->l,mid);
            addnode(p->rson,mid+1,p->r);
        }
        falazy(p);
        if(p->lson->r>=r)change(p->lson,l,r,num);
        else{
	        if(p->rson->l<=l)change(p->rson,l,r,num);
	        else{
		        change(p->lson,l,p->lson->r,num);
		        change(p->rson,p->rson->l,r,num);
	        }
        }
        update(p);
    }
    int query(node *p,int l,int r){
    	//printf("%d %d %d %d\n",p->l,p->r,p->sum,p->lazy);
        if(l>r)return 0;
        if(p->l==l && p->r==r)
            return p->sum;
        if(!p->lson || !p->rson){
            int mid=(p->l+p->r)/2;
            addnode(p->lson,p->l,mid);
            addnode(p->rson,mid+1,p->r);
        }
        falazy(p);
        if(p->lson->r>=r)return query(p->lson,l,r);
        else{
	        if(p->rson->l<=l)return query(p->rson,l,r);
	        else{
		        return query(p->lson,l,p->lson->r)+query(p->rson,p->rson->l,r);
	        }
        }
    }
}seg;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int c;
        scanf("%d",&c);
        seg.change(seg.root,i,i,c);
    }
    for(int i=1;i<=m;i++){
        int c,x,y,k;
        scanf("%d",&c);
        if(c==1){
            scanf("%d%d%d",&x,&y,&k);
            seg.change(seg.root,x,y,k);
        }
        if(c==2){
            scanf("%d%d",&x,&y);
            printf("%d\n",seg.query(seg.root,x,y));
        }
    }
    //system("pause");
    return 0;
}
