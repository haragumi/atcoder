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

string N;
vector<int> n;
long long dp[105][2][5];

int main(){
  cin >> N;
  int k; cin >> k;

  for(auto a : N){
    n.push_back(a-'0');
  }
  int l = N.size();

  dp[0][0][0] = 1;
  for(int i = 0; i < l; i++){
    for(int smaller = 0; smaller < 2; smaller++){
      for(int j = 0; j < 4; j++){
        for(int x = 0; x <= (smaller ? 9 : n[i]); x++){
          dp[i + 1][smaller || x < n[i]][j + (x!=0)] += dp[i][smaller][j];
        }
      }
    }
  }

  cout << dp[l][0][k] + dp[l][1][k] << endl;
}
