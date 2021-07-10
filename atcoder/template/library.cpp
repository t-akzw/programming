struct UnionFind{
	vector<int> par,rank;
	UnionFind(int N){
		par.assign(N,0);
		rank.assign(N,0);
		rep(i,N) par[i]=i;
	}
	int find(int x){
		if(par[x]==x) return x;
		return par[x]=find(par[x]);
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
	void unite(int x,int y){
		x=find(x),y=find(y);
		if(x==y) return;
		if(rank[x]<rank[y]) swap(x,y);
 
		//x becomes root
		par[y]=x;
		if(rank[x]==rank[y]) rank[x]++;
	}
};

void dijkstra(ll s, VVE &G, V &d) {
  PG q; q.push(P(0,s));
  rep(i,dist.size()) d[i] = INFI; d[s] = 0;
  while (!q.empty()) {
    P p = q.top(); q.pop();
    auto v = p.second;
    if (d[v] < p.first) continue;
    for(ll i = 0; i < G[v].size(); i++) {
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        q.push(P(d[e.to], e.to));
      }
    }
  }
}