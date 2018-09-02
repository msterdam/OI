//LCA在线倍增法实际上是将上升的步数用二进制来表示，经过试跳一个级数来确定是否
//可以上升，最终找到LCA，整个路径长度假设是n的话，这个过程就是O(logn)的。

//代码如下

//1. DFS预处理出所有节点的深度和父节点 
void dfs(int u)
{
  int i;
  for(i=head[u];i!=-1;i=next[i])  
  {  
    if (!deep[to[i]])
    {			
      deep[to[i]] = deep[u]+1;
      p[to[i]][0] = u; //p[x][0]保存x的父节点为u;
      dfs(to[i]);
    }
  }
}
// 2. 初始各个点的2^j祖先是谁 ,其中 2^j (j =0...log(该点深度))倍祖先，
//1倍祖先就是父亲，2倍祖先是父亲的父亲......。
void init()
{
  int i,j;
  //p[i][j]表示i结点的第2^j祖先
  for(j=1;(1<<j)<=n;j++)
    for(i=1;i<=n;i++)
      if(p[i][j-1]!=-1)
        p[i][j]=p[p[i][j-1]][j-1];//i的第2^j祖先就是i的第2^(j-1)祖先的第2^(j-1)祖先
}
//3.从深度大的节点上升至深度小的节点同层，如果此时两节点相同直接返回此节点，即lca。
//否则，利用倍增法找到最小深度的 p[a][j]!=p[b][j]，此时他们的父亲p[a][0]即lca。 
int lca(int a,int b)//最近公共祖先
{
  int i,j;
  if(deep[a]<deep[b])swap(a,b);
  for(i=0;(1<<i)<=deep[a];i++);
  i--;
  //使a，b两点的深度相同
  for(j=i;j>=0;j--)
    if(deep[a]-(1<<j)>=deep[b])
      a=p[a][j];
  if(a==b)return a;
  //倍增法，每次向上进深度2^j，找到最近公共祖先的子结点
  for(j=i;j>=0;j--)
  {
    if(p[a][j]!=-1&&p[a][j]!=p[b][j])
    {
      a=p[a][j];
      b=p[b][j];
    }
  }
  return p[a][0];
}
