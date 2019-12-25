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

double dp[2][75][75][75];
int num[6];

int main() {
  ll n,d; cin >> n >> d;
  while(d%2==0) num[2]++,d/=2;
  while(d%3==0) num[3]++,d/=3;
  while(d%5==0) num[5]++,d/=5;
  if(d>1){
    cout << 0 << endl;
    return 0;
  }

  dp[0][0][0][0] = 1.0;
  FOR(i,1,n){
    int cur,nex;
    if(i%2==1) cur = 0, nex = 1;
    else cur = 1, nex = 0;
    MEMSET(dp[nex],0);

    FOR(x,0,70){
      FOR(y,0,50){
        FOR(z,0,40){
          if(dp[cur][x][y][z]==0) continue;
          dp[nex][x][y][z] += dp[cur][x][y][z]/6.0;
          dp[nex][min(69,x+1)][y][z] += dp[cur][x][y][z]/6.0;
          dp[nex][x][min(49,y+1)][z] += dp[cur][x][y][z]/6.0;
          dp[nex][min(69,x+2)][y][z] += dp[cur][x][y][z]/6.0;
          dp[nex][x][y][min(39,z+1)] += dp[cur][x][y][z]/6.0;
          dp[nex][min(69,x+1)][min(49,y+1)][z] += dp[cur][x][y][z]/6.0;
        }
      }
    }
  }

  double ans = 0.0;

  FOR(x,num[2],70){
    FOR(y,num[3],50){
      FOR(z,num[5],40){
        int cur;
        if(n%2==1) cur = 1;
        else cur = 0;
        ans += dp[cur][x][y][z];
      }
    }
  }

  cout << std::setprecision(30);
  cout << ans << endl;

}

