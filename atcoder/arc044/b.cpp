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

// for graph
vector<vector<pair<int, int>>> G(100100);
vector<int> c;

string s[505];
bool used[505][505];
int d[505][505];
const int di[] = {-1,0,1,0}, dj[] = {0,-1,0,1};

void sample_solve();
int gcd(ll m, ll n);
void make_graph(int n);

void dfs(int v, int p) {
  for (auto e : G[v]) {
    debug(e.first);
    if (e.first == p) continue;
    c[e.first] = (e.second & 1 ? c[v]^1 : c[v]);
    dfs(e.first, v);
  }
  return;
}

// =================================
// Main Logic
// =================================
void solve() {
  int n;
  cin >> n;
  make_graph(n);
  rep(i, n) c.push_back(0);
  dfs(0, -1);
  for (auto p : c) cout << p << endl;
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

void make_graph(int n) {
  for (int i=0; i<n-1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--; v--;
    G[u].push_back({v, w});
    G[v].push_back({u, w});
  }  
}