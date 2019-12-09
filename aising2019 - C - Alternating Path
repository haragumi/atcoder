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

// union by size + path having
class UnionFind {
public:
    vector <ll> par; // 各元の親を表す配列
    vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)

    // Constructor
    UnionFind(ll sz_): par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }

    // Member Function
    // Find
    ll root(ll x) { // 根の検索
        while (par[x] != x) {
            x = par[x] = par[par[x]]; // x の親の親を x の親とする
        }
        return x;
    }

    // Union(Unite, Merge)
    bool merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける）
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool issame(ll x, ll y) { // 連結判定
        return root(x) == root(y);
    }

    ll size(ll x) { // 素集合のサイズ
        return siz[root(x)];
    }
};

bool visited[160010];

int main() {
    // input(sunippets: inpv, inpn, inps)
    ll H,W;
    cin >> H >> W;
    UnionFind uf(H*W);

    char shapmap[H][W];

    FOR(i,0,H-1){
      string s; cin >> s;
      FOR(j,0,W-1){
        shapmap[i][j] = s[j];
      }
    }

    FOR(i,0,H-1){
      FOR(j,0,W-1){
        if(i==H-1){
          if(j!=W-1){
            if(shapmap[i][j]!=shapmap[i][j+1]) uf.merge(i*W+j, i*W+j+1);
          }
        } else if(j==W-1){
          if(shapmap[i][j]!=shapmap[i+1][j]) uf.merge(i*W+j, (i+1)*W+j);
        } else {
          if(shapmap[i][j]!=shapmap[i+1][j]) uf.merge(i*W+j, (i+1)*W+j);
          if(shapmap[i][j]!=shapmap[i][j+1]) uf.merge(i*W+j, i*W+j+1);
        }
      }
    }

    map<ll,ll> bombnum;

    FOR(i,0,H-1){
      FOR(j,0,W-1){
        if(shapmap[i][j]=='#') ++bombnum[uf.root(i*W+j)];
      }
    }
    ll ans = 0;
    FOR(i,0,H-1){
      FOR(j,0,W-1){
        if(!visited[uf.root(i*W+j)]){
          if(uf.size(i*W+j)>1){
            ans += bombnum[uf.root(i*W+j)] * (uf.size(i*W+j) - bombnum[uf.root(i*W+j)]);
          } 
          visited[uf.root(i*W+j)] = true;
        }
      }
    }

    cout << ans << endl;

    return 0;
}

