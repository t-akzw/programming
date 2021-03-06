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

int myxor(int a, int b) {
  if (a == b) {
    return 0;
  } else {
    return 1;
  }
}

// =================================
// Main Logic
// =================================
void solve() {
  int ans = 0;
  int n;
  string s;
  string t;
  cin >> n >> s >> t;
  vector<int> vs(n), vt(n), vand(n);
  rep(i,n) {
    vs.at(i) = s.at(i) - '0';
    vt.at(i) = t.at(i) - '0';
  }
  int vsc = 0, vtc = 0;
  rep(i, n) {
    if (vs.at(i) == 1) vsc += 1;
    if (vt.at(i) == 1) vtc += 1;
  }
  if (vsc != vtc) {
    cout << 0 << endl;
    return;
  }
  rep(i,n) {
    int myxorx;
    myxorx = myxor(vs.at(i), vt.at(i));
    int myandx;
    myandx = myxorx&vs.at(i);
    vand.at(i) = myandx;
  }
  int flag = 0;
  int l =0, r=0;
  vector<int> vl, vr;
  rep(i,n) {
    if (flag && vs.at(i) == vt.at(i)) continue; 
    if (flag && vt.at(i) == 0) {
      r = i;
      flag = 0;
      vr.push_back(r);
    }
    debug(vand.at(i));
    if(!flag && vand.at(i)) {
      l = i;
      vl.push_back(l);
      flag = 1;
    }
    debug(l);
    debug(r);
  }
  rep(i, n) {
    debug(vl.at(i)); debug(vr.at(i));
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