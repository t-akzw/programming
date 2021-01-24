#include <bits/stdc++.h>
#include <utility>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<P> VP;

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
 
int main() {
  int n;
  int cost;
  int a, b, c;
  ll tmp = 0;
  ll ans = 0;
  VP vp;
  cin >> n >> cost;
  rep(i, n) {
  	cin >> a >> b >> c;
    vp.push_back({a, c});
    vp.push_back({b+1, -c});
  }
  sort(vp.begin(), vp.end());
  rep(i, 2*n-1) {
    cout << vp[i].first << " " << vp[i].second << " " << (vp[i+1].first - vp[i].first) << endl;
    tmp += vp[i].second;
    if(tmp > cost) { ans += cost * (vp[i+1].first - vp[i].first); }
    else { ans += tmp * (vp[i+1].first - vp[i].first); };
    cout << "ans: " << ans << ", tmp: " << tmp << endl;
  }
  cout << ans << endl;
  return 0;
}
