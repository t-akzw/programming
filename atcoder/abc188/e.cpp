#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
 
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<vector<int>> to(n);
  rep(i,m) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    to[x].push_back(y);
  }
  const int INF = 1001001001;
  vector<int> dp(n,INF*2);
  int ans = -INF;
  rep(i,n) {
    ans = max(ans, a[i]-dp[i]);
    for (int j : to[i]) {
      dp[j] = min(dp[j], dp[i]);
      dp[j] = min(dp[j], a[i]);
    }
  }
  cout << ans << endl;
  return 0;
}