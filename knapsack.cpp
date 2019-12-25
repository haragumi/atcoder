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
#define sqr(x)  ((x) * (x)) 
#define cub(x)  ((x) * (x) * (x))
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// int gcd(int a,int b){return b?gcd(b,a%b):a;}

int dp[110][100100];

int main() {
  int n,w; cin >> n >> w;
  int value[n],weight[n];
  FOR(i,0,n-1){
    cin >> value[i] >> weight[i];
  }
  
  FOR(i,0,n-1){
    FOR(j,0,w){
      if(j>=weight[i]) chmax(dp[i+1][j],max(dp[i][j], dp[i][j-weight[i]] + value[i]));
      dp[i+1][j] = dp[i][j];
    }
  }

  cout << dp[n][w] << endl;
}

