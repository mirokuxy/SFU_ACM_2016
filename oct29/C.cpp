#include <cstdio>

int d[100];
int k;
int f[1024*1024+100][8];

int dfs(int u, int e, int cost){
  if (u==0)return cost;
  if (f[u][e]!=0)return f[u][e];
  int m=1000000000;
  for (int i=0;i<k;i++){
    int v;
    if (u&(1<<i)){
      int nu=u^(1<<i);
      if (e==0) v=dfs(nu,d[i]-1,cost+d[i]);
      if (e>d[i]-1) v=dfs(nu,0,cost+1);
      else v=dfs(nu,d[i]-e-1,cost+d[i]-e);
      if (v<m)m=v;
    }
  }
  f[u][e]=m;
  return m;
}

int main(){
  
  scanf("%d",&k);
  for (int i=0;i<k;i++){
    scanf("%d",&d[i]);
  }
  printf("%d\n",dfs((1<<k)-1,0,0));
}