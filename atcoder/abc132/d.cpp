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

// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4765
const int mod = 1000000007;
struct mint {
  ll x;
  mint(ll x=0):x(x%mod){}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
};

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

mint c[4005][4005];

void init() {
  c[0][0] = 1;

  rep(i, 4001) {
    rep(j, i+1) {
      c[i+1][j] += c[i][j];
      c[i+1][j+1] += c[i][j];
    }
  }
}

mint comb(int n, int k) {
  return c[n][k];
}

mint f2(int n, int k) {
  return comb(n+k-1, k-1);
}

mint f(int n, int k) {
  if (n < k) return 0;
  if (n == 0 && k == 0) return 1;
  if (k < 1) return 0;
  return f2(n-k, k);
}

// =================================
// Main Logic
// =================================
void solve() {
  init();
  int n, k;
  cin >> n >> k;

  rep2(i, 1, k+1) {
    mint blue = f(k,i);
    debug(blue.x);
    mint red = 0;
    { 
      red += f(n-k,i-1);
      red += f(n-k,i);
      red += f(n-k,i);
      red += f(n-k,i+1);
    }
    mint ans = blue*red;
    printf("%lld\n", ans.x);
  }
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