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

int factorial(int n) {
  int ans = 1;
  for(int i = 1; i <= n; i++) {
    ans *= i;
  }
  return ans;
}

int combination(int n, int k) {
  return factorial(n) / factorial(k) / factorial(n - k);
}

// =================================
// Main Logic
// =================================
void solve() {
  int ans = 0;
  string s;
  cin >> s;
  int cnt_o = 0;
  int cnt_q = 0;
  int cnt_x = 0;
  for(char x : s) {
    if (x == 'o') cnt_o += 1;
    if (x == '?') cnt_q += 1;
    if (x == 'x') cnt_x += 1;
  }
  if (cnt_x == 10) {
    ans = 0;
    return;
  }
  if (cnt_o == 0) {
    ans += cnt_q*cnt_q*cnt_q*cnt_q;
  } else if (cnt_o == 1) {
    if (cnt_q == 0) {
      ans = 1;
    } else if (cnt_q == 1) {
      //oooo
      ans += 1;
      //ooo?
      ans += 4*cnt_q;
      //oo(?1)(?1)
      ans += 6*cnt_q;
      //o(?1)(?1)(?1)
      ans += 4*cnt_q;
    } else if (cnt_q == 2) {
      //oooo
      ans += 1;
      //ooo?
      ans += 4*cnt_q;
      //oo(?1)(?1)
      ans += 6*cnt_q*cnt_q;
      //oo(?1)(?2)
      ans += 12*cnt_q*(cnt_q-1);
      //o(?1)(?1)(?1)
      ans += 4*cnt_q*cnt_q*cnt_q;
      //o(?1)(?2)(?2)
      ans += 12*cnt_q*(cnt_q-1);
    } else {
      //oooo
      ans += 1;
      //ooo?
      ans += 4*cnt_q;
      //oo(?1)(?1)
      ans += 6*cnt_q;
      //oo(?1)(?2)
      ans += 12*cnt_q*(cnt_q-1);
      //o(?1)(?1)(?1)
      ans += 4*cnt_q;
      //o(?1)(?2)(?2)
      ans += 12*cnt_q*(cnt_q-1);
      //o(?1)(?2)(?3)
      ans += 24*cnt_q*(cnt_q-1)*(cnt_q-2);
    }
  } else if (cnt_o == 2) {
    if (cnt_q == 0) {
      //(o1)(o2)(o1)(o1)
      ans += 4;
      //(o1)(o2)(o1)(o2)
      ans += 6;
    } else if (cnt_q == 1) {
      //(o1)(o2)(o1)(o1)
      ans += 4;
      //(o1)(o2)(o1)(o2)
      ans += 6;
      // (o1)(o2)(!o)(!o)
      ans += 12*cnt_q;
      // (o1)(o2)(o1|o2)(!o)
      ans += 12*2*cnt_q;
    } else {
      //(o1)(o2)(o1)(o1)
      ans += 4;
      //(o1)(o2)(o1)(o2)
      ans += 6;
      // (o1)(o2)(!o)(!o)
      ans += 12*cnt_q;
      // (o1)(o2)(o1|o2)(!o)
      ans += 12*2*cnt_q;
      // (o1)(o2)(!o1)(!o2)
      ans += 24*cnt_q*(cnt_q-1);
    }
  } else if (cnt_o == 3) {
    if (cnt_q == 0) {
      //(o1)(o2)(o3)(o1|o2|o3)
      ans += 12*3;
    } else {
      //(o1)(o2)(o3)(o1|o2|o3)
      ans += 12*3;
      //(o1)(o2)(o3)(!o)
      ans += 24*cnt_q;
    }
  } else if (cnt_o == 4) {
    //(o1)(o2)(o3)(o4)
    ans += 24;
  } else if (cnt_o > 4) {
    ans = 0;
  } else {
    ans = 0;
  }
  //debug(cnt_o);
  //debug(cnt_q);
  //debug(cnt_x);
  //debug(combination(4, 2));
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