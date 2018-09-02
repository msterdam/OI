#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct segtree{
    long long top;
    long long mod;
    #define maxn 100000
    struct node{
        long long lazy,tlazy,sum;
        long long l,r;
        node *lson,*rson;
    }pool[maxn*4],*root;
    void addnode(node *&p,long long l,long long r){
        p=&pool[top++];
        p->lazy=0;
        p->tlazy=1;
        p->sum=0;
        p->l=l;p->r=r;
    }
    void falazy(node *p){
        if(p->l==p->r)return;
        p->lson->tlazy=(p->lson->tlazy*p->tlazy)%mod;
        p->rson->tlazy=(p->rson->tlazy*p->tlazy)%mod;
        p->lson->lazy=(p->lson->lazy*p->tlazy+p->lazy)%mod;
        p->rson->lazy=(p->rson->lazy*p->tlazy+p->lazy)%mod;

        p->lson->sum=(p->lson->sum*p->tlazy + p->lazy*(p->lson->r-p->lson->l+1))%mod;
        p->rson->sum=(p->rson->sum*p->tlazy + p->lazy*(p->rson->r-p->rson->l+1))%mod;

        p->lazy=0;
        p->tlazy=1;
    }
    void update(node *p){
        p->sum=(p->lson->sum+p->rson->sum)%mod;
    }
    segtree(void){
        top=0;
        addnode(root,0,maxn);
    }
    void add(node *p,long long l,long long r,long long num){
        if(p->l==l && p->r==r){
            p->lazy=(p->lazy+num)%mod;
            p->sum=(p->sum+num*(p->r-p->l+1))%mod;
            return;
        }
        if(!p->lson || !p->rson){
            long long mid=(p->l+p->r)/2;
            addnode(p->lson,p->l,mid);
            addnode(p->rson,mid+1,p->r);
        }
        falazy(p);
        if(p->lson->r>=r)add(p->lson,l,r,num);
        else if(p->rson->l<=l)add(p->rson,l,r,num);
        else{
            add(p->lson,l,p->lson->r,num);
            add(p->rson,p->rson->l,r,num);
        }
        update(p);
    }
    void times(node *p,long long l,long long r,long long num){
        if(num==1)return;
        if(p->l==l && p->r==r){
            p->tlazy=(p->tlazy*num)%mod;
            p->lazy=(p->lazy*num)%mod;
            p->sum=(p->sum*num)%mod;
            return;
        }
        if(!p->lson || !p->rson){
            long long mid=(p->l+p->r)/2;
            addnode(p->lson,p->l,mid);
            addnode(p->rson,mid+1,p->r);
        }
        falazy(p);
        if(p->lson->r>=r)times(p->lson,l,r,num);
        else if(p->rson->l<=l)times(p->rson,l,r,num);
        else{
            times(p->lson,l,p->lson->r,num);
            times(p->rson,p->rson->l,r,num);
        }
        update(p);
    }
    long long query(node *p,long long l,long long r){
        if(p->l==l && p->r==r){
            return p->sum;
        }
        if(!p->lson || !p->rson){
            return 0;
        }
        falazy(p);
        if(p->lson->r>=r)return query(p->lson,l,r);
        else if(p->rson->l<=l)return query(p->rson,l,r);
        else{
            return (query(p->lson,l,p->lson->r)+query(p->rson,p->rson->l,r))%mod;
        }
    }
}seg;
int main(){
    long long n,m;
    scanf("%lld%lld%lld",&n,&m,&seg.mod);
    for(long long i=1;i<=n;i++){
        long long c;
        scanf("%lld",&c);
        seg.add(seg.root,i,i,c);
    }
    for(long long i=1;i<=m;i++){
        long long q,x,y,k;
        scanf("%lld",&q);
        if(q==1){
            scanf("%lld%lld%lld",&x,&y,&k);
            seg.times(seg.root,x,y,k);
        }
        if(q==2){
            scanf("%lld%lld%lld",&x,&y,&k);
            seg.add(seg.root,x,y,k);
        }
        if(q==3){
            scanf("%lld%lld",&x,&y);
            printf("%lld\n",seg.query(seg.root,x,y));
        }
    }
    //system("pause");
    return 0;
}
