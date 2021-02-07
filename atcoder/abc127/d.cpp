a#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll, ll>;
using V = vector<ll>;
using VV = vector<V>;
using M = map<ll, ll>;
using Q = queue<ll>;
using PQ = priority_queue<ll>;
using ST = stack<ll>;
using Graph = vector< vector<ll> >;

#define rep(i, n)     for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define rbfor(v, vec) for(auto const& v : vec)

const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;
template<typename T> bool chmax(T &a, const T &b) {if (a < b){a = b;return true;}else{return false;}}
template<typename T> bool chmin(T &a, const T &b) {if (a > b){a = b;return true;}else{return false;}}

void sample_solve();

// =================================
// Main Logic
// =================================
void solve() {
  int n, m;
  int b, c;
  cin >> n >> m;
  V a(n);
  priority_queue<pair<int, int>> q;
  rep(i, n) {
    cin >> a.at(i);
    q.push(make_pair(a.at(i), 1));
  }
  rep(i, m) {
    cin >> b >> c;
    q.push(make_pair(c, b));
  }
  ll ans = 0;
  rep(i, n) {
    auto p = q.top();
    q.pop();
    ans += p.first;
    if(p.second > 1) {
      p.second--;
      q.push(p);
    }
  }
  cout << ans << endl;
  // rbfor(v, a) cout << v << endl;
}
// =================================

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  solve();
  //sample_solve();
  return 0;
}