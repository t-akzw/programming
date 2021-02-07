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

const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;
template<typename T> bool chmax(T &a, const T &b) {if (a < b){a = b;return true;}else{return false;}}
template<typename T> bool chmin(T &a, const T &b) {if (a > b){a = b;return true;}else{return false;}}

void sample_solve();

// =================================
// Main Logic
// =================================
void solve() {

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

// ---------------
// https://atcoder.jp/contests/apg4b/tasks_print
// ---------------

void sample_solve() {
  // basic usage
  V vi(3, 1);
  rbfor(v, vi) cout << v << endl;

  cout << "-- at" << endl;
  vi.at(1) = 3;
  cout << vi.at(1) << endl;

  cout << "-- pop_back" << endl;
  vi.pop_back();
  rbfor(v, vi) cout << v << endl;

  cout << "-- reverse" << endl;
  reverse(vi.begin(), vi.end());
  rbfor(v, vi) cout << v << endl;

  cout << "-- sort" << endl;
  sort(vi.begin(), vi.end());
  rbfor(v, vi) cout << v << endl;

  //insert: a.insert(a.end(), tmp.begin(), tmp.end()); vectorの結合

  cout << "-- graph" << endl;
  Graph g(3, vector<ll>(4, 10));
  g.at(2).at(2) = 1;
  cout << g.at(2).at(2) << endl;
  cout << g.at(0).at(0) << endl;

  int x = 12345;
  double pi = 3.14159265358979;
  printf("x = %d, pi = %lf\n", x, pi);
  // int: %d, int64_t: %ld, double: %lf. char: %c

  string s = to_string(x);
  cout << s + "yen" << endl;

  int n = stoi(s);
  cout << n << endl;
  // str2int: stoi, str2int64_t: stoll, str2double: stod
  
  cout << "-- pair" << endl;
  P p(1, 10);
  cout << p.first << ": " << p.second << endl;
  ll a, b;
  tie(a, b) = p;
  cout << a << ": " << b << endl;

  cout << "-- tuple" << endl;
  tuple<ll, ll, ll> t(1, 10, 100);
  cout << get<1>(t) << endl; // 10
  ll c;
  tie(a, ignore, c) = t;
  cout << a << "," << "," << c << endl;

  cout << "-- map" << endl;
  M m;
  m[11] = 111;
  m[22] = 222;
  m[33] = 333;
  m.erase(33);
  cout << "11: " << m.at(11) << ", count:" << m.count(33) << endl;

  cout << "-- queue" << endl;
  Q q;
  q.push(1000);
  cout << q.front() << endl;
  q.push(2);
  q.pop();
  bool is_empty = q.empty();
  cout << q.size() << ", " << is_empty << endl;

  cout << "-- priority_queue" << endl;
  PQ pq;
  pq.push(1000);
  pq.push(2);
  pq.push(8);
  pq.push(100);
  ll top1 = pq.top();
  pq.pop();
  ll top2 = pq.top();
  cout << top1 << ", " << top2 << ", size: " << pq.size() << endl;

  cout << "-- stack" << endl;
  ST st;
  st.push(10);
  st.push(1);
  st.push(3);
  cout << st.top() << endl;
  st.pop();
  cout << st.top() << endl;

  cout << "-- struct" << endl;
  struct MyPair {
    int x;
    string y;
    MyPair(int a, string b) {
      cout << "constructor called" << endl;
      x = a;
      y = b;
    }
    void print() {
      cout << "x = " << x << endl;
      cout << "y = " << y << endl;
    }
  };
  MyPair mpa = {11, "hoge"};
  mpa.print();

  cout << "-- bitset" << endl;
  bitset<8> bsa("00011011");
  bitset<8> bsb("00110101");
  auto bsc = bsa & bsb;
  cout << "1: " << bsc << endl;         // 1: 00010001
  cout << "2: " << (bsc << 1) << endl;  // 2: 00100010
  auto bsd = bsa ^ bsb;
  cout << bsd << endl;
  bsd.set(0, 1);
  cout << bsd << endl;
  auto is_one = bsd.test(0);
  cout << is_one << endl;
  bitset<4> bsx(4);
  cout << bsx << endl;
  // .reset: 全ビット0に
  // .set: 全ビット1に
  // .flip: 全ビット反転
  // .all: 全ビット1かどうか
  // .any: 1があるかどうか
  // .to_string, to_ullong
  // .[位置]: 位置にアクセス

  cout << "-- lambda" << endl;
  // 最大値を保持する変数
  int max_num = 0;
 
  // 今まで受け取った値の中から最も大きな値を返す関数
  auto update_max = [&](int n) {
    if (max_num < n) {
      max_num = n;
    }
    return max_num;
  };
  cout << update_max(5) << endl;
  cout << update_max(2) << endl;
}

// -- info
// int: 最小値：-2147483648, 最大値：2147483647

// -- stl
// find(iter1, iter2, num)
// lower_bound(iter1, iter2, num): イテレータの範囲内から指定した値以上の最小の要素を探す
// upper_bound(iter1, iter2, num): イテレータの範囲内から指定した値より大きな最小の要素を探す
