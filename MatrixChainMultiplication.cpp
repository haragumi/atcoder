// 区間DP

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) int((a).size())
#define SORT(c) sort((c).begin(),(c).end())
#define MEMSET(v, h) memset((v), h, sizeof(v))
#define sqr(x) ((x) * (x))
#define bit(n) (1LL<<(n))
#define pcnt(x) __builtin_popcountll(x)
#define PB push_back
#define MP make_pair
#define endl "\n"
using Edge = pair<int,int>;
using Graph = vector<vector<Edge>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
// ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

ll dp[110][110];
const ll MAX = 1001001001001001;

int main() {
  int n; cin >> n;
  ll p[n+1];
  FOR(i,0,n-1){
    cin >> p[i] >> p[i+1];
  }
  FOR(i,1,n){
    FOR(j,1,n){
      if(i==j) continue;
      else dp[i][j] = MAX;
    }
  }
  
  FOR(l,2,n){
    FOR(i,1,n-l+1){ //連鎖長がlのものでループ
      int j = i+l-1;
      FOR(k,i,j-1){
        ll q = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j];
        chmin(dp[i][j],q);
      }
    }
  }
  cout << dp[1][n] << "\n";

}
