// スリザーリンクを解こうとした。失敗作

#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)

int main() {
  int n; cin >> n;
  int input[n][n];
  FOR(i,0,n-1){
    string s; cin >> s;
    FOR(j,0,n-1){
      if(s[j]=='-') input[i][j] = -1;
      else input[i][j] = (int)(s[j]-'0');
    }
  }

  int cnt = 0;
  int hor[n+1][n]; int ver[n][n+1];
  FOR(i,0,n){
    FOR(j,0,n-1){
      hor[i][j] = -1;
    }
  }
  FOR(i,0,n-1){
    FOR(j,0,n){
      ver[i][j] = -1;
    }
  }

  while(cnt!=69){
    FOR(i,0,n-1){
      FOR(j,0,n-1){
        int notdraw = 0;
        int sum4 = 0;
        if(hor[i][j]<0) ++notdraw;
        if(hor[i+1][j]<0) ++notdraw;
        if(ver[i][j]<0) ++notdraw;
        if(ver[i][j+1]<0) ++notdraw;

        if(hor[i][j]==1) ++sum4;
        if(hor[i+1][j]==1) ++sum4;
        if(ver[i][j]==1) ++sum4;
        if(ver[i][j+1]==1) ++sum4;

        if(input[i][j]==0){
          if(hor[i][j]<0) {hor[i][j]=0; ++cnt;}
          if(hor[i+1][j]<0) {hor[i+1][j]=0; ++cnt;}
          if(ver[i][j]<0) {ver[i][j]=0; ++cnt;}
          if(ver[i][j+1]<0) {ver[i][j+1]=0; ++cnt;}
        }
        else if(input[i][j]==sum4){
          if(hor[i][j]<0) {hor[i][j]=0; ++cnt;}
          if(hor[i+1][j]<0) {hor[i+1][j]=0; ++cnt;}
          if(ver[i][j]<0) {ver[i][j]=0; ++cnt;}
          if(ver[i][j+1]<0) {ver[i][j+1]=0; ++cnt;}
        }
        else if(input[i][j]-sum4==notdraw){
          if(hor[i][j]<0) {hor[i][j]=1; ++cnt;}
          if(hor[i+1][j]<0) {hor[i+1][j]=1; ++cnt;}
          if(ver[i][j]<0) {ver[i][j]=1; ++cnt;}
          if(ver[i][j+1]<0) {ver[i][j+1]=1; ++cnt;}
        }
      }
    }

    FOR(i,0,n){
      FOR(j,0,n){
        int connect = 0;
        int notconnect = 0;
        if(j-1>=0 && hor[i][j-1]==1) ++connect;
        if(j<=n-1 && hor[i][j]==1) ++connect;
        if(i-1>=0 && ver[i-1][j]==1) ++connect;
        if(i<=n-1 && ver[i][j]==1) ++connect;

        if(j-1>=0 && hor[i][j-1]==-1) ++notconnect;
        if(j<=n-1 && hor[i][j]==-1) ++notconnect;
        if(i-1>=0 && ver[i-1][j]==-1) ++notconnect;
        if(i<=n-1 && ver[i][j]==-1) ++notconnect;

        if(connect==1 && notconnect==1){
          if(j-1>=0 && hor[i][j-1]==-1) {hor[i][j-1]=1; ++cnt;}
          if(j<=n-1 && hor[i][j]==-1) {hor[i][j]=1; ++cnt;}
          if(i-1>=0 && ver[i-1][j]==-1) {ver[i-1][j]=1; ++cnt;}
          if(i<=n-1 && ver[i][j]==-1) {ver[i][j]=1; ++cnt;}
        }

        if(connect==2){
          if(j-1>=0 && hor[i][j-1]==-1) {hor[i][j-1]=0; ++cnt;}
          if(j<=n-1 && hor[i][j]==-1) {hor[i][j]=0; ++cnt;}
          if(i-1>=0 && ver[i-1][j]==-1) {ver[i-1][j]=0; ++cnt;}
          if(i<=n-1 && ver[i][j]==-1) {ver[i][j]=0; ++cnt;}
        }
      }
    }

    cout << cnt << "\n";
  }

  // cout << hor[0][1] << " " << hor[0][2] << " " << hor[0][3] << "\n";

  FOR(i,0,2*(n)){
    if(i%2==0){
      FOR(j,0,n-1){
        if(hor[(i/2)][j]==-1) cout << "-" << "?";
        else cout << "-" << hor[(i/2)][j];
      }
      cout << "\n";
    }
    else{
      FOR(j,0,n){
        if(ver[(i/2)][j]==-1) cout << "?" << "-";
        else cout << ver[(i/2)][j] << "-";
      }
      cout << "\n";
    }
  } 
}
