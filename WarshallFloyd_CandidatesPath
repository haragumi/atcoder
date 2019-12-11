#include <bits/stdc++.h>
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

int dist[100][100];
const int INF = pow(10,9);

int main() {
  int n,m;
  cin >> n >> m;
  int a[m],b[m],c[m];
  FOR(i,0,n-1){
    FOR(j,0,n-1){
      if(i==j) dist[i][j] = 0;
      else dist[i][j] = INF;
    }
  }
  FOR(i,0,m-1){
    cin >> a[i] >> b[i] >> c[i];
    --a[i]; --b[i];
    dist[a[i]][b[i]] = c[i];
    dist[b[i]][a[i]] = c[i];
  }
  
  FOR(k,0,n-1){
    FOR(i,0,n-1){
      FOR(j,0,n-1){
        if(i==j) continue;
        if(i==k) continue;
        if(j==k) continue;
        if(dist[i][j]>dist[i][k]+dist[k][j]){
          dist[i][j] = dist[i][k]+dist[k][j];
        }
      }
    }
  }

  int ans = 0;

  FOR(i,0,m-1){
    bool ok = false;
    FOR(j,0,n-1){
      FOR(k,0,n-1){
        if(j==k) continue;

        if(dist[j][a[i]]+c[i]+dist[b[i]][k]==dist[j][k]) {
          ok = true;
        }
      }
    }
    if(!ok) ++ans;
  }

  cout << ans << endl;

}

