#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
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
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
// ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int dp[105][10500];

int main(void){
  int n; int W; cin >> n >> W;
  int v[n],w[n];
  FOR(i,0,n-1) cin >> v[i] >> w[i];

  FORD(i,n-1,0){
    FOR(j,0,W){
      if(j<w[i]){
        dp[i][j] = dp[i+1][j];
      } else {
        dp[i][j] = max(dp[i+1][j], dp[i+1][j-w[i]] + v[i]);
      }
    }
  }
  cout << dp[0][W] << endl;


}
