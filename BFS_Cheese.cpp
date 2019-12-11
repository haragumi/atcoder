#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORL(i,x) for(int i=head[x];i;i=nxt[i])
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define PB push_back
#define MP make_pair
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int INF = 10000000;
int ans = 0;
int R,C,cheese;

int sy,sx,gy,gx;
int d[1010][1010];
char chmap[1010][1010];

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int bfs(){
  queue<pair<int,int>> que;
  
  FOR(i,0,R-1){
    FOR(j,0,C-1){
      d[i][j] = INF;
    }
  }
  que.push(pair<int,int>(sy,sx));
  d[sy][sx] = 0;

  while(que.size()){
    pair<int,int> p = que.front();
    que.pop();

    if(p.first == gy && p.second == gx) break;

    FOR(i,0,3){
      int ny = p.first + dy[i];
      int nx = p.second + dx[i];

      if(nx>=0 && nx<C && ny>=0 && ny<R && d[ny][nx] == INF && chmap[ny][nx]!='X'){
        que.push(pair<int,int>(ny,nx));
        d[ny][nx] = d[p.first][p.second] + 1;
      }
    }
  }
  return d[gy][gx];
}


int main() {
  cin >> R >> C >> cheese;
  vector<pair<int,int>> sxy;

  FOR(i,0,R-1){
    string s; cin >> s;
    FOR(j,0,C-1){
      chmap[i][j] = s[j];
      if(s[j]=='S') sxy.PB(MP(i,j));
    }
  }
  FOR(k,1,cheese){
  FOR(i,0,R-1) {
    FOR(j,0,C-1){
      if((int)(chmap[i][j]-'0')==k) {
        sxy.PB(MP(i,j));
      }
    }
  }
  }
  FOR(i,0,cheese-1){
    sy = sxy[i].first; sx = sxy[i].second;
    gy = sxy[i+1].first; gx = sxy[i+1].second;
    ans += bfs();
  }

  cout << ans << endl;
  
}

