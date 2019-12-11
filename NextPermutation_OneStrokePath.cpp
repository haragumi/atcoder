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

bool edge[10][10];

int main() {
  int n,m;
  cin >> n >> m;
  int a[m],b[m];
  FOR(i,0,m-1){
    cin >> a[i] >> b[i];
    --a[i]; --b[i];
    edge[a[i]][b[i]] = true;
    edge[b[i]][a[i]] = true;
  }

  vector<int> perm(n);
  FOR(i,0,n-1) perm[i] = i;

  int ans = 0;

  do{
    if(perm[0]!=0) break;

    bool ok = true;
    FOR(i,0,n-2) {
      if(!edge[perm[i]][perm[i+1]]) ok = false;
    }
    if(ok) ++ans;

  } while (next_permutation(perm.begin(),perm.end()));

  cout << ans << endl;

}

