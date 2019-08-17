#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
typedef vector<ii> vii;
typedef vector<pair<ii, ll>> viii;


#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define ROF(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define ifile(a) freopen((a), "r", stdin)
#define ofile(a) freopen((a), "w", stdout)
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); //cout.tie(NULL)
#define PI 3.1415926535897932384626433832795
#define mem(x, val) memset((x), (val), sizeof(x))
#define sz(x) (ll)(x).size()
#define endl '\n'
#define clockon ll t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }
#define oo 2000000000000000000LL
#define EPS 1e-6
#define MOD 1000000007
#define etr "\n"
#define INF 1E10


struct target{
	ll x, y, t;
	double ev;
};

ll n;
target targets[1010];
double dp[1010];

double calculateSteps(target &a, target &b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double optimalStructure(ll level){
	if(level == n) return 0;
	if(dp[level] != -1) return dp[level];
	double mx = 0;
	FOR(i, level+1, n){
		if((calculateSteps(targets[level], targets[i]) + targets[level].t) <= targets[i].t){
			mx = max(optimalStructure(i), mx);
		}
	}
	return dp[level] = mx + targets[level].ev;
}

double getResult(){
	double mx = 0;
	FOR(i, 0, n) mx = max(mx, optimalStructure(i));
	return mx;
}

int main(){
	cin >> n;
	FOR(i, 0, n){
		cin >> targets[i].x >> targets[i].y >> targets[i].t >> targets[i].ev;
	}
	FOR(i, 0, n) dp[i] = -1;
	sort(targets, targets+n, [](const target &t1, const target &t2){
		return t1.t < t2.t;
	});

	cout << setprecision (15) << getResult() << etr;
	return 0;
}