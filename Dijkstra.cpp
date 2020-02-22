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
using Graph = vector<vector<Edge>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
// ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int V,E;
Graph G;
int d[100050]; //MAX_V
const int INF = 1001001001;

void dijkstra(int s){
  priority_queue<Edge, vector<Edge>, greater<Edge>> que;
  fill(d, d+V, INF);
  d[s] = 0;
  que.push(Edge(0,s));

  while(!que.empty()){
    Edge p = que.top(); que.pop();
    int v = p.second;
    if(d[v]<p.first) continue;
    for(auto x: G[v]){
      if(d[x.first]>d[v]+x.second){
        d[x.first] = d[v]+x.second;
        que.push(Edge(d[x.first],x.first));
      }
    }
  }
}

int main(void){
  int r;
  cin >> V >> E >> r;
  G.assign(V,vector<Edge>());
  FOR(i,0,E-1){
    int s,t,d; cin >> s >> t >> d;
    G[s].PB(MP(t,d));
    // G[t].PB(MP(s,d));
  }
  dijkstra(r);
  FOR(i,0,V-1){
    if(d[i]==INF) cout << "INF" << endl;
    else cout << d[i] << endl;
  }
}


