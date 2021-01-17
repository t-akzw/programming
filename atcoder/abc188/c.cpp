#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
 
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
  cin >> n;
  int n2 = 1 << n;
  int ah[n2];
  int al[n2];
  int max_l = -1;
  int max_l_idx = -1;
  int max_h = -1;
  int max_h_idx = -1;

  rep(i, n2) {
    if (i < n2/2) {
      cin >> al[i];
      if (al[i] > max_l) {
        max_l = al[i];
        max_l_idx = i;
        //cout << max_l << endl;
      }      
    } else {
      cin >> ah[i];
      if (ah[i] > max_h) {
        max_h = ah[i];
        max_h_idx = i;
        //cout << max_h << endl;
      }   
    }
  }
  if (max_l > max_h) {
    cout << max_h_idx+1;
  } else {
    cout << max_l_idx+1;
  }
  return 0;
}:w
