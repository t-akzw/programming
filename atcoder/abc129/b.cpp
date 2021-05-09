#include <bits/stdc++.h>
 
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
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
 
const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;
const int INFI = 1000000000;
template<typename T> bool chmax(T &a, const T &b) {if (a < b){a = b;return true;}else{return false;}}
template<typename T> bool chmin(T &a, const T &b) {if (a > b){a = b;return true;}else{return false;}}
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
 
// for dfs
string s[505];
bool used[505][505];
int d[505][505];
 
const int di[] = {-1,0,1,0}, dj[] = {0,-1,0,1};
 
void sample_solve();
int gcd(ll m, ll n);
bool dfs(int i, int j);
void bfs();
 
// =================================
// Main Logic
// =================================
void solve() {
  int ans = INFI;
  int n;
  cin >> n;
  vector<int> w(n);
  rep(i,n) cin >> w.at(i);
  rep(i,n) {
    int s1 = 0, s2 = 0;
    rep2(j, 0, i) s1 += w.at(j);
    rep2(j, i, n) s2 += w.at(j);
    if (abs(s1-s2) < ans) ans = abs(s1-s2);
    //debug(s1);
    //debug(s2);
    //debug(ans);
  }
  cout << ans << endl;
}
// =================================
 
int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  solve();
  return 0;
}
 
// ---------------
// https://atcoder.jp/contests/apg4b/tasks_print
// ---------------
 
typedef tuple<string, int ,int> TUPLE;
bool comp(TUPLE lhs, TUPLE rhs) {
  if (get<0>(lhs) == get<0>(rhs)) {
    return get<1>(lhs) > get<1>(rhs);
  } else {
    return get<0>(lhs) < get<0>(rhs);
  }
}
 
int gcd(ll m, ll n) {
  if (n == 0) return m;
  return gcd(n, m%n);
}