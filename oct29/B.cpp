#include <cstdio>

int money[11000];
int e[101000][2];
int fe[11000];
int v[11000];
int n,m;
int tot;

int ce=1;
void link(int x,int y){
  e[ce][0]=y;
  e[ce][1]=fe[x];
  fe[x]=ce;
  ce++;
}

void dfs(int x){
  v[x]=1;
  tot+=money[x];
  int i=fe[x];
  while (i>0){
    if (v[e[i][0]]==0){
      dfs(e[i][0]);
    }
    i=e[i][1];
  }
}


int work(){
  for (int i=0;i<n;i++){
    if (v[i]==0){
      tot=0;
      dfs(i);
      if (tot!=0) return 0;
    }
  }
  return 1;
}

int main(){
  
  scanf("%d%d",&n,&m);
  for (int i=0;i<n;i++){
    scanf("%d",&money[i]);
  }
  for (int i=0;i<m;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    link(x,y);link(y,x);
  }
  if (work()) printf("POSSIBLE\n");
  else printf("IMPOSSIBLE\n");

}