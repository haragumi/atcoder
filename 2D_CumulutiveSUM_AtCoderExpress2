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

ll p[550][550];

int main() {
  ll n,m,q; cin >> n >> m >> q;
  FOR(i,0,m-1){
    int l,r; cin >> l >> r;
    ++p[l][r];
  }
  FOR(i,1,n){
    FOR(j,1,n){
      p[i][j] += p[i][j-1];
      p[i][j] += p[i-1][j];
      p[i][j] -= p[i-1][j-1];
    }
  }

  FOR(i,0,q-1){
    int l,r; cin >> l >> r;
    cout << p[r][r] - p[l-1][r] - p[r][l-1] + p[l-1][l-1] << endl;
  }
}

