#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int,int>;
 
int main() {
  int a, b;
  int ans;
  cin >> a >> b;
  if(a >= 13) {
    ans = b;
  } else if(6 <= a && a <= 12) {
    ans = b/2;
  } else {
    ans = 0;
  }
  cout << ans << endl;
  return 0;
}