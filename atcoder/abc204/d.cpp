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
using VP = vector<P>;

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
bool dfs(int i, int j);
void bfs();
ll gcd(ll m, ll n);
ll lcm(ll x, ll y);
bool compare(P a, P b);
void vp_sort(VP& vp, bool asc);

// =================================
// Main Logic
// =================================
void solve() {
  int ans = 0;
  int n;
  cin >> n;
  vector<int> t(n);
  rep(i,n) cin >> t[i];

  int o1 = 0, o2 = 0;
  sort(t.begin(), t.end());
  reverse(t.begin(), t.end());

  rep(i,n) {
    if (o1 > o2) {
      o2 += t[i];
    } else {
      o1 += t[i];
    }
  }
  if (o1 <= o2) ans = o2; else ans = o1;

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

// 最大公約数
ll gcd(ll m, ll n) {
  if (n == 0) return m;
  return gcd(n, m%n);
}

// 最小公倍数
ll lcm(ll x, ll y) {
    return x / gcd(x, y) * y;//先に割り算をして掛けられる数を小さくして掛け算を行う
}

bool compare(P a, P b) {
  if(a.first != b.first){ return a.first > b.first; }
  if(a.second != b.second){return a.second > b.second;}
  return true;
}

void vp_sort(VP& vp, bool asc) {
  sort(vp.begin(), vp.end(), compare);
  if(asc) reverse(vp.begin(), vp.end());
}

  /*
  // 比較関数の例: tuple 0で辞書順ソート、1で降順ソート
  cout << "-- comp of tuple" << endl;
  vector<TUPLE> vt;
  vt.push_back(make_tuple("khabarovsk", 20, 1));
  vt.push_back(make_tuple("moscow", 10, 2));
  vt.push_back(make_tuple("kazan", 50, 3));
  vt.push_back(make_tuple("kazan", 35, 4));
  vt.push_back(make_tuple("moscow", 60, 5));
  vt.push_back(make_tuple("khabarovsk", 40, 6));
  sort(vt.begin(), vt.end(), comp);

  rep(i, 6) cout << get<0>(vt.at(i)) << ":" << get<1>(vt.at(i)) << ":" << get<2>(vt.at(i)) << endl;
  */