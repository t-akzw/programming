#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
 
int main() {
  int n, m;
  int l, r;
  int ans = 0;
  cin >> n >> m;
  int maxl = 1;
  int minr = 100100100;
  rep(i, m) {
    cin >> l >> r;
    if (l >= maxl) maxl = l;
    if (r <= minr) minr = r;
  }
  if (maxl > minr) {
    ans = 0;
  } else {
    ans = minr - maxl + 1;
  }
  cout << ans << endl;
  return 0;
}