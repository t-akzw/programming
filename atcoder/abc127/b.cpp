#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
 
int main() {
  int r, D, x2000;
  int ans;
  cin >> r >> D >> x2000;
  ans = x2000;
  rep(i,10) {
    ans = r*ans - D;
    cout << ans << endl;
  }
  return 0;
}