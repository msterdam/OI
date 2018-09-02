#include <iostream>
#include <algorithm>
#include <memory.h>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int N,cnt=0,q,num;
bool flag;
struct node{
    int d,rnd,size,lazy,cnt;
    node *ch[2],*parent;       
}pool[100005],*root,*t,*NO;
int size(node *p)
{
    int ret=0;
    if(p) ret=p->size;
    return ret;
}
void push(node *p)
{
    if(p->ch[0]) p->ch[0]->lazy+=p->lazy;   
    if(p->ch[1]) p->ch[1]->lazy+=p->lazy;
    p->lazy=0;  
}
node *find(node *r,int k)//2¨¦?¨°?????ak¦Ì??¨²¦Ì? 
{
    if(cnt==0 || r==NULL)return NO;
    if(size(r->ch[0])<=k-1 && size(r->ch[0])>=k-r->cnt)return r;
    else if(size(r->ch[0])>=k)return find(r->ch[0],k);
    else if(r->ch[1])return find(r->ch[1],k- r->cnt - size(r->ch[0]));
    return NO;
}
node *findnum(node *r,int k)//2¨¦?¨°?¦Ì?ak¦Ì??¨²¦Ì? 
{
    if(cnt==0 || r==NULL)return NO;
    if(r->d==k)return r;
    if(r->d<k && r->ch[1])return findnum(r->ch[1],k);
    else if(r->ch[0])return findnum(r->ch[0],k);
    return NO;
}
void update(node *p)
{
    if(!p)return;
    int size=p->cnt;
    if(p->ch[0])size+=p->ch[0]->size; 
    if(p->ch[1])size+=p->ch[1]->size;   
    p->size=size;  
}
void right_rotate(node *p)
{
    node *parent=p->parent,*gp=p->parent->parent,*rson=p->ch[1];
    parent->ch[0]=rson;
    if(rson) rson->parent=parent;
    p->ch[1]=parent;
    parent->parent=p;
    p->parent=gp;
    if(gp) gp->ch[gp->ch[1]==parent]=p;
    if(parent==root) root=p;
    update(parent);
    update(p); 
}
void left_rotate(node *p)
{
    node *parent=p->parent,*gp=p->parent->parent,*lson=p->ch[0];
    parent->ch[1]=lson;
    if(lson)lson->parent=parent;
    p->ch[0]=parent;
    parent->parent=p;
    p->parent=gp;
    if(gp)gp->ch[gp->ch[1]==parent]=p;
    if(parent==root) root=p;
    update(parent);
    update(p);
}
void rotate(node *p)
{
    if(p==root || !p->parent || p->rnd > p->parent->rnd)return;
    int f=p->parent->ch[1]==p;
    if(f==1) left_rotate(p);
    else right_rotate(p);
    rotate(p);     
}
void insert(node *r,node *np)
{
    if(r==NULL)
    {
        if(root==NULL)root=np;
        r=np;
        return;
    }
    int f=r->d < np->d;
    r->size++;
    push(r);
    if(r->ch[f]==NULL)
    {
        r->ch[f]=np;
        np->parent=r;
    }
    else
        insert(r->ch[f],np);
    rotate(np);
}
void del(node *p)
{
    if(p->cnt>1)
    {
        p->cnt--;
        p->size--;
        while(p!=root)
         {
             p=p->parent;
             p->size--;    
         }
        return;        
    }
    int f;
    if(p==root) f=0;
    else f=p->parent->ch[1]==p;
    if(p->ch[0]==NULL && p->ch[1]==NULL)
    {
        p->parent->ch[f]=NULL;
        while(p!=root)
        {
        	p=p->parent;
        	p->size--;
        }
        return;
    }
    else if(p->ch[0] && p->ch[1])
    {
        if(p->ch[0]->rnd < p->ch[1]->rnd)
            right_rotate(p->ch[0]);
        else
            left_rotate(p->ch[1]);
    }
    else
    {
        if(p->ch[0]) right_rotate(p->ch[0]);
        else left_rotate(p->ch[1]);
    }
    del(p);
}
void printnode(node *p)
{
    /*cout<<"d:"<<p->d<<endl; 
    cout<<"rnd:"<<p->rnd<<endl;   
    cout<<"size:"<<p->size<<endl; */
    cout<<p->d<<endl;      
}
void printtree(node *r,int layer)
{
    if(r==NULL)return;
    cout<<"dep:"<<layer<<" d:"<<r->d<<"  ";
    if(r->ch[0])cout<<"ch[0]"<<r->ch[0]->d;
    if(r->ch[1])cout<<" ch[1]"<<r->ch[1]->d;
    cout<<endl;
    if(r->ch[0])printtree(r->ch[0],layer+1);
    if(r->ch[1])printtree(r->ch[1],layer+1);
}
int que(node *r,int num,int ans)
{
    if(r==NULL)return ans;
    if(r->d==num)return ans + size(r->ch[0]);
    else if(r->d < num) return que(r->ch[1],num,ans + size(r->ch[0]) + r->cnt);
    else return que(r->ch[0],num,ans);
}
void inserts(int x) 
{
     node *p=findnum(root,num);
     if(p!=NO)
     {
        p->cnt++;
        p->size++;
        while(p!=root)
         {
             p=p->parent;
              p->size++;    
         }
        return;      
     }
     t=&pool[++cnt];
     t->d=num;
     t->cnt=1;
     t->size=1;
     t->rnd=abs(rand());
     insert(root,t);
}
int front(node *p,int x,int ans)
{
    if(p==NULL)return ans;
    if(x<p->d)return front(p->ch[0],x,ans);
    else if(p->d!=x)return front(p->ch[1],x,p->d);
    return max(front(p->ch[1],x,ans),front(p->ch[0],x,ans));
}
int next(node *p,int x,int ans)
{
    if(p==NULL)return ans;
    if(p->d<x)return next(p->ch[1],x,ans);
    else if(p->d!=x)return next(p->ch[0],x,p->d);
    return min(next(p->ch[0],x,ans),next(p->ch[1],x,ans));
}
int main()
{
    //freopen("testdata (1).in","r",stdin);
    //freopen("testoutput.txt","w",stdout);
    flag=false;
    memset(pool,0,sizeof(pool));
    srand((unsigned)time(NULL));
    NO=&pool[++cnt];
    NO->d=233333;
    NO->size=0;
    NO->cnt=0;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        scanf("%d%d",&q,&num);
        if(q==0) printtree(root,0);
        if(q==1) inserts(num);
        if(q==2) del(findnum(root,num));
        if(q==3) cout<<que(root,num,0)+1<<endl;
        if(q==4) printnode(find(root,num));
        if(q==5) cout<<front(root,num,1<<31)<<endl;
        if(q==6) cout<<next(root,num,1<<30)<<endl;
    }
    return 0;
}
