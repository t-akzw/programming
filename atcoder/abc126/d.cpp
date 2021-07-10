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
#define pb push_back

const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;
const int INFI = 1000000000;
template<typename T> bool chmax(T &a, const T &b) {if (a < b){a = b;return true;}else{return false;}}
template<typename T> bool chmin(T &a, const T &b) {if (a > b){a = b;return true;}else{return false;}}
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }

// for graph
vector<vector<pair<int, int>>> G(100100);

string s[505];
bool used[505][505];
int d[505][505];
const int di[] = {-1,0,1,0}, dj[] = {0,-1,0,1};

void sample_solve();
int gcd(ll m, ll n);

V color(100005, -1);

void dfs(int v, int c) {
  if (color[v] != -1) return;
  color[v] = c;
  for (auto e : G[v]) {
    e.second%2==0 ? dfs(e.first, c) : dfs(e.first, 1-c);
  }
  return;
}

// =================================
// Main Logic
// =================================
void solve() {
  int n; cin>>n;
  rep(i,n-1) { int u,v,w; cin>>u>>v>>w; u--; v--; G[u].pb({v,w}); G[v].pb({u,w}); }
  dfs(0,0);
  rep(i,n) cout << color[i] << endl;
}
// =================================

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  solve();
  // sample_solve();
  return 0;
}