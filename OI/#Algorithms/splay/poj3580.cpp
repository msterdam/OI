#include <cstdio>
#include <algorithm>
using namespace std;
const long long maxn=210100;
const long long inf=~0U>>2;
struct node{
    long long d,lazy,mi,size;
    long long ch[2],fa;
    bool rev;
}p[maxn];
long long n,m,root,top=0;
long long size(long long x){
    if(x>0 && x<=top)return p[x].size;
    return 0;
}
long long newp(long long d,long long fa){
    long long x=top++;
    p[x].d=d;
    p[x].fa=fa;
    p[x].size=1;
    p[x].lazy=0;
    p[x].rev=false;
    p[x].mi=d;
    return x;
}
void pushdown(long long x){
    if(x==0)return;
    p[x].d+=p[x].lazy;
    p[p[x].ch[0]].lazy+=p[x].lazy;
    p[p[x].ch[1]].lazy+=p[x].lazy;
    p[x].mi+=p[x].lazy;
    p[x].lazy=0;
    if(p[x].rev){
        swap(p[x].ch[0],p[x].ch[1]);
        p[p[x].ch[0]].rev^=1;
        p[p[x].ch[1]].rev^=1;
        p[x].rev^=1;
    }
}
void update(long long x){
    if(x==0)return;
    p[x].size=size(p[x].ch[0])+size(p[x].ch[1])+1;
    p[x].mi=min(p[x].d+p[x].lazy,min(p[p[x].ch[0]].mi+p[p[x].ch[0]].lazy,p[p[x].ch[1]].mi+p[p[x].ch[1]].lazy));//

}
void inorder(long long x){
    if(x==0)return;
    pushdown(x);
    inorder(p[x].ch[0]);
    if(p[x].d!=inf)printf("%lld ",p[x].d);
    inorder(p[x].ch[1]);
}
void inform()
{
    printf("\n");
    printf("inorder: ");inorder(root);printf("\n");
    printf("size of tree: %lld\n",p[root].size);
    printf("root number: %lld\n",root);
    printf("\n");
}
void rotate(long long x){     
    //printf("rotate: %lld",x);
    if(x==0 || x==root)return;
    long long y=p[x].fa;
    long long z=p[y].fa;
    pushdown(z);pushdown(y);pushdown(x);
    long long k=p[y].ch[1]==x;
    p[z].ch[p[z].ch[1]==y]=x;
    p[x].fa=z;
    p[y].ch[k]=p[x].ch[k^1];
    p[p[x].ch[k^1]].fa=y;
    p[x].ch[k^1]=y;
    p[y].fa=x;
    update(y);update(x);update(z);
    if(z==0)root=x;
}
void splay(long long x,long long tar){
    //printf("splay: %lld to %lld\n",x,tar);
    if(x==0)return; //<------------------
    if(x==tar)return ;
    while(p[x].fa!=tar){
        long long y=p[x].fa;
        long long z=p[y].fa;
        if(z!=tar)
            (p[z].ch[0]==y)^(p[y].ch[0]==x)?rotate(x):rotate(y);
        rotate(x);
    }
    if(tar==0)root=x;
}
long long kth(long long k){//return x:p[p[x].ch[0]].size+1=k
    //printf("kth: %lld\n",k);
    k++;//
    long long x=root; 
    while(k>0){
        pushdown(x);//<-------
        if(size(p[x].ch[0])+1==k)return x;
        else if(size(p[x].ch[0])+1>k)x=p[x].ch[0];
        else k-=size(p[x].ch[0])+1,x=p[x].ch[1];
    }
    //printf("kth failed\n");
    return x;
}
void rev(long long s,long long t){
    if(s>=t)return;
    s--;t++;//
    long long y=kth(s);
    long long x=kth(t);
    splay(y,0);
    splay(x,root);
    p[p[x].ch[0]].rev^=1;
}
void insert(long long pos,long long num){
    //printf("insert %lld %lld\n",pos,num);
    long long y=kth(pos);
    long long x=kth(pos+1);
    splay(y,0);
    splay(x,root);
    p[x].ch[0]=newp(num,x);
    update(x);
    update(y);
}
void del(long long pos){
    long long y=kth(pos-1);
    long long x=kth(pos+1);
    splay(y,0);
    splay(x,root);
    p[x].ch[0]=0;
    update(x);
    update(y);
}
void add(long long l,long long r,long long num){
    long long y=kth(l-1);
    long long x=kth(r+1);
    splay(y,0);
    splay(x,root);
    p[p[x].ch[0]].lazy+=num;
    update(x);
    update(y);
}
long long Min(long long l,long long r){
    long long y=kth(l-1);
    long long x=kth(r+1);
    splay(y,0);
    splay(x,root);
    return p[p[x].ch[0]].mi+p[p[x].ch[0]].lazy;
}
void revolve1(long long s,long long t,long long num){
	if(num<0){
        num%=t-s+1;
        num=t-s+1+num;
        
    }
	num%=(t-s+1);
    if(num==0)return;
    rev(s,t);
	rev(s,s+num-1);
	rev(s+num,t);
}
void revolve(long long l,long long r,long long T)
{
    long long len = r-l+1;
    T = ((T%len)+len)%len;

    if(!T) return;
    rev(l,r-T);
    rev(r-T+1,r);
    rev(l,r);
}
long long read(){
    long long x;
    scanf("%lld",&x);
    return x;
}
void build1(){
    newp(0,0);//father of root
    root=newp(inf,0);//prenode
    long long cur=root;
    for(long long i=1;i<=n;i++){
        p[cur].ch[1]=newp(i,cur);
        p[cur].size=n-i+3;
        cur++;
    }
    p[cur].ch[1]=newp(inf,cur);//afternode
    p[cur].size=2;
    cur=top-1;
    while(cur!=0){
        cur=p[cur].fa;
        update(cur);
    }
}
void build2(){
    newp(inf,0);//father of root
    p[0].size=0;
    p[0].ch[1]=1;
    p[0].ch[0]=1;
    root=newp(inf,0);//prenode
    p[root].ch[1]=newp(inf,root);//afternode
    p[root].size=2;
    for(long long i=1;i<=n;i++){
        long long x;
        scanf("%lld",&x);
        insert(i-1,x);
    }
}
int main(){
    scanf("%lld",&n);
    build2();
    scanf("%lld",&m);
    for(long long i=1;i<=m;i++){
	    char c[10];
	    long long x,y,z;
	    scanf("%s",c);
	    switch(c[0]){
		    case 'A':scanf("%lld%lld%lld",&x,&y,&z);add(x,y,z);break;//add
		    case 'R':{
			    if(c[3]=='O') {scanf("%lld%lld%lld",&x,&y,&z);revolve(x,y,z);break;}//revolve
			    if(c[3]=='E') {scanf("%lld%lld",&x,&y);rev(x,y);break;}//rev
			}
		    case 'I':scanf("%lld%lld",&x,&y);insert(x,y);break;//insert
		    case 'D':scanf("%lld",&x);del(x);break;//delete
		    case 'M':scanf("%lld%lld",&x,&y);printf("%lld\n",Min(x,y));break;//Min
		    case '1':inform();break;
		    case '2':{
		    	for(long long i=1;i<=top;i++)
		    	    printf("%lld ",size(i));
		    	printf("\n");
			    break;
			}
		}
	}
    //inorder(root);
    system("pause");
    return 0;
}
