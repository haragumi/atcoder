#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) int((a).size())
#define SORT(c) sort((c).begin(),(c).end())
#define PB push_back
#define MP make_pair
#define MEMSET(v, h) memset((v), h, sizeof(v))
#define endl "\n"
using Edge = pair<int,int>;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
// ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

Graph G;
int color[1050];

bool dfs(int v, int c) {
  color[v] = c;
  for (auto e : G[v]) {
    if (color[e] == c) return false;
    if (color[e] == 0 && !dfs(e, -c)) return false;
  }
  return true;
}

int main(void){
  int n; cin >> n;
  G.assign(n,vector<int>());
  FOR(i,0,n-1){
    int a,b; cin >> a >> b;
    G[a].PB(b);
    G[b].PB(a);
  }
  FOR(i,0,n-1){
    if(color[i]==0){
      if(!dfs(i,1)){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
}
