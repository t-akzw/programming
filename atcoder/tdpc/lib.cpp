V n2b(ll n, ll keta) {
  V v(keta);
  rep(i, keta) {
    v[i] = n%2;
    n /= 2;
  }
  return v;
}

ll b2n(V &v) {
  ll ans = 0;
  ll cnt = 0;
  for(auto c : v) {
    ans += pow(2, cnt)*c;
    ++cnt;
  }
  return ans;
}

ll n2count(ll n, ll keta) {
  auto b = n2b(n, keta);
  ll cnt = 0;
  rep(i,b.size()) if (b[i]) ++cnt;
  return cnt;
}