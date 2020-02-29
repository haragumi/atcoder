// http://www.cc.kyoto-su.ac.jp/~yamada/ap/backtrack.html

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
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

const int N = 8;
int k;
bool isinput[8];

void changeBoard(int board[N][N], int i, int j, int d)
{
    int k;

    for (k = 0; k < N; k++) { 
        board[i][k] += d;             /* 横方向 */
        board[k][j] += d;             /* 縦方向 */
    }
    if (i > j) {
        for (k = 0; k < N-(i-j); k++) {
            board[k+(i-j)][k] += d;   /* 右下がり斜め方向 (i > jのとき） */
        }
    } else {
        for (k = 0; k < N-(j-i); k++) {
            board[k][k+(j-i)] += d;   /* 右下がり斜め方向 (i <= jのとき） */
        }
    }
    if (i+j < N) {
        for (k = 0; k <= i+j; k++) {
            board[i+j-k][k] += d;     /* 左下がり斜め方向（i +j < Nのとき） */
        }
    } else {
        for (k = i+j-N+1; k < N; k++) {
            board[i+j-k][k] += d;     /* 左下がり斜め方向（i+j >= Nのとき） */
        }
    }
}

void setQueen(int queen[N], int board[N][N], int i)
{
    int j;
    
    if (i == N) {                              /* 解が見つかった */
        FOR(i,0,N-1){
          FOR(j,0,N-1){
            if(queen[i]==j) cout << "Q";
            else cout << ".";
          }
          cout << "\n";
        }
        return;
    }

    if (isinput[i]) {
      setQueen(queen, board, i+1);
    }
    
    for (j = 0; j < N; j++) {
        if (board[i][j] == 0) {                /* (i,j) の位置に置けるならば */
            queen[i] = j;                      /* (i,j) の位置にクイーンを置く */
            changeBoard(board, i, j, +1);      /* (i,j) から縦横斜めの方向のboard値を+1する */
            setQueen(queen, board, i+1);       /* i+1 行目のクイーンの位置を決める */
            changeBoard(board, i, j, -1);      /* (i,j) から縦横斜めの方向のboard値を元に戻す */
        }
    }
}

int main() {
  cin >> k;
  int queen[N];
  int board[N][N];
  MEMSET(queen,0);
  MEMSET(board,0);
  FOR(i,0,k-1){
    int x,y; cin >> x >> y;
    isinput[x] = true;
    queen[x] = y;
    changeBoard(board, x, y, +1);
  }
  setQueen(queen, board, 0);
}

