#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n = 5;
    int a[n] = {4,2,1,3,5};
    int dp[n];
    const int INF = 1000000000;
    fill(dp, dp+n, INF);
    for(int i=0; i<n; i++){
      *lower_bound(dp, dp+n, a[i]) = a[i];
    }
    cout << lower_bound(dp, dp+n, INF) - dp << endl;

    return 0;
}
