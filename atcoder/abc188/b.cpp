#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int a[100005];
int b[100005];
 
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
  ll res = 0LL;
  cin >> n;
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  rep(i, n) {
  	res += a[i]*b[i];
  }
  puts( ( res == 0 ) ? "Yes" : "No" );
  // cout << res << endl;
  return 0;
}