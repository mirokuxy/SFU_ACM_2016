#include <cstdio>
#include <deque>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 1000 + 2;
const int MAXM = 1000 + 2;
const int MAXNM = MAXN * MAXM;
const int MAXQ = 10000 + 5;

class UnionSet{
  int groups[MAXNM];
  int count;
  int maxGroup;

public:

  UnionSet(int n){
    for(int i=1;i<=n;i++){
      groups[i] = i;
    }
    count = n;
    maxGroup = n;
  }

  int findGroup(int i){
    queue<int> q;
    while(groups[i] != i){
      q.push(i);
      i = groups[i];
    }
    while(!q.empty()){
      int j = q.front();
      q.pop();
      groups[j] = i;
    }
    return i;
  }

  void joinGroup(int i, int j){
    int gi = findGroup(i);
    int gj = findGroup(j);
    if(gi != gj){
      groups[gi] = gj;
      count -= 1;
    }
  }

  int groupCount(){
    return count;
  }

  int newGroup(){
    maxGroup += 1;
    groups[maxGroup] = maxGroup;
    count += 1;
    return maxGroup;
  }

};

struct Query{
  int x1, y1, x2, y2;
  Query(int x1, int y1, int x2, int y2){
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
  }
};
struct Point{
  int x,y;
  Point(int x, int y){
    this->x = x;
    this->y = y;
  }
};

vector<Query> queries;
int matrix[MAXN][MAXM], group[MAXN][MAXM];
int groupCount;

Point diff[4] = { Point(1,0), Point(-1,0), Point(0,1), Point(0,-1) };

void markGroup(int n, int m, int x, int y, int g){
  group[x][y] = g;

  deque<Point> q;
  q.push_back(Point(x,y));

  while(!q.empty()){
    Point p = q.front();
    q.pop_front();
    
    for(int i=0;i<4;i++){
      Point diffP = diff[i];
      int xx,yy;
      xx = p.x + diffP.x;
      yy = p.y + diffP.y;
      if(0<=xx && xx<n && 0<=yy && yy<m && matrix[xx][yy] == 0 && group[xx][yy] == -1){
        group[xx][yy] = g;
        q.push_back(Point(xx,yy));
      }
    }
  }
}


int main(){

  int n,m,q;

  scanf("%d %d %d", &n, &m, &q);

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
      matrix[i][j] = 0;
      group[i][j] = -1; 
    }


  for(int i=0;i<q;i++){
    int x1,y1,x2,y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    x1--; y1--; x2--; y2--;
    queries.push_back(Query(x1,y1,x2,y2));
    
    if(x1 == x2){
      int x = x1;
      for(int y=y1; y<=y2; y++)
        matrix[x][y] += 1;
    } else {
      int y = y1;
      for(int x=x1; x<=x2; x++)
        matrix[x][y] += 1;
    }
  }

  groupCount = 0;
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
      if(matrix[i][j] == 0 && group[i][j] == -1){
        groupCount += 1;
        markGroup(n, m, i, j, groupCount);
      }
    }

  UnionSet uSet(groupCount);
  vector<int> count;

  for(int i=queries.size()-1; i>=0; i--){
    count.push_back(uSet.groupCount());

    Query query = queries[i];
    vector<Point> points;

    for(int x=query.x1; x<=query.x2; x++)
      for(int y=query.y1; y<=query.y2; y++){
        matrix[x][y] -=1;
        if(matrix[x][y] == 0){
          group[x][y] = uSet.newGroup();

          for(int i=0;i<4;i++){
            Point diffP = diff[i];
            int xx,yy;
            xx = x + diffP.x;
            yy = y + diffP.y;
            if(0<=xx && xx<n && 0<=yy && yy<m && matrix[xx][yy] == 0){
              uSet.joinGroup(group[x][y], group[xx][yy]);
            }
          }
        }
      }
  }

  for(int i=count.size()-1; i>=0; i--){
    printf("%d\n", count[i]);
  }

  return 0;
}





























