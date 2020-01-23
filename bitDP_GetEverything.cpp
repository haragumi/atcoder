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
#define MEMSET(v, h) memset((v), h, sizeof(v))
#define PB push_back
#define MP make_pair
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll dp[5000];
ll const INF = 1001001001;

int main(void) {
  ll n,m; cin >> n >> m;
  ll a[m],b[m];
  ll c[m];
  MEMSET(c,0);

  FOR(i,0,m-1){
    cin >> a[i] >> b[i];
    FOR(j,0,b[i]-1) {
      ll t; cin >> t; --t;
      c[i] += (1<<t);
    }
  }

  FOR(j,0,4999){
    dp[j] = INF;
  }
  dp[0] = 0;

  FOR(i,0,(1<<n)-1){
    FOR(j,0,m-1){
      ll t = i | c[j];
      ll cost = dp[i] + a[j];
      chmin(dp[t],cost); 
    }
  }

  if(dp[(1<<n)-1]==INF) cout << -1 << endl;
  else cout << dp[(1<<n)-1] << endl;
}
