#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<map>
#include<set>
#include<bitset>
#include<iostream>
#include<sstream>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define pb push_back
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 105, MW = 10005, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

int n, w, c;
struct dat{int v, w, c;};
dat d[MX];
bool cmp(const dat& a, const dat& b){ return a.c < b.c;}

int dp[2][MW*2][55][2]; // 0:unused 1:used
int o, p;

int main(){
	int x, y;
	cin >> n >> w >> c;
	
	rep(i,n){
		cin >> d[i].w >> d[i].v >> d[i].c;
	}
	sort(d,d+n,cmp);
	o = 0; p = 1;
	
	int pre = -1;
	bool same;
	
	rep(j,w+1)rep(k,c+1){
		dp[o][j][k][0] = 0;
		dp[o][j][k][1] = -INF;
	}
	rep(i,n){
		same = (pre == d[i].c);
		pre = d[i].c;
		x = d[i].w; y = d[i].v;
		rep(j,w+1)rep(k,c+1){
			dp[p][j][k][0] = dp[o][j][k][0];
			dp[p][j][k][1] = -INF;
		}
		rep(j,w+1)rep(k,c+1){
			if(same){
				dp[p][j][k][1] = max(dp[p][j][k][1],dp[o][j][k][1]);
				dp[p][j+x][k][0] = max(dp[p][j+x][k][0],dp[o][j][k][1]+y);
				dp[p][j+x][k][1] = max(dp[p][j+x][k][1],dp[o][j][k][1]+y);
			}
			dp[p][j+x][k+1][0] = max(dp[p][j+x][k+1][0],dp[o][j][k][0]+y);
			dp[p][j+x][k+1][1] = max(dp[p][j+x][k+1][1],dp[o][j][k][0]+y);
		}
		swap(o,p);
	}
	
	cout << dp[o][w][c][0] << endl;
	
	return 0;
}




