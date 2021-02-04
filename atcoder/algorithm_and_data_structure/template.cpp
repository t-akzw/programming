#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<int, int>;
using VI = vector<int>;
using Graph = vector< vector<ll> >;

#define rep(i, n)     for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define rbfor(v, vec) for(auto const& v : vec)

const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;
template<typename T> bool chmax(T &a, const T &b) {if (a < b){a = b;return true;}else{return false;}}
template<typename T> bool chmin(T &a, const T &b) {if (a > b){a = b;return true;}else{return false;}}

// ----

void sample_solve() {
  // basic usage
  cout << "hoge" << endl;
  VI vi(3);
  rbfor(v, vi) cout << v << endl;
  vi.at(1) = 3;
  cout << vi.at(1) << endl;
}

void solve() {

}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  // solve();
  sample_solve();
  return 0;
}