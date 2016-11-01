#include <cstdio>

int main(){
  int a,b,c;
  scanf("%d%d%d",&a,&b,&c);
  a+=b;
  int ans=0;
  while (a>=c){
    ans+=a/c;
    a=(a%c)+(a/c);
  }
  printf("%d\n",ans);
  return 0;
}
