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
#define INF 10E10

ll x1x, y1y, x2x, y2y;

string s;
ll n;
ll x3x, y3y;

ll dist(ll ax, ll ay, ll bx, ll by){
	return abs(ax - bx) + abs(ay - by);
}

int main(){
	cin >> x1x >> y1y >> x2x >> y2y;
	cin >> n;
	cin >> s;

	ii partialSum[n];
	ii prev = mp(0, 0);
	FOR(i, 0, n){
		char c = s[i];
		if(c == 'U') partialSum[i] = mp(prev.first, prev.second+1);
		else if(c == 'D') partialSum[i] = mp(prev.first, prev.second-1);
		else if(c == 'R') partialSum[i] = mp(prev.first+1, prev.second);
		else partialSum[i] = mp(prev.first-1, prev.second);
		prev = partialSum[i];
	}

	ll posRes = - 1;
	ll l = 1, r = 4 * (1E14) + 10, m;
	while(l <= r){
		m = l + (r-l) / 2;
		ll total = m / n;
		ll rest = m % n;
		if(dist(x1x + (total * partialSum[n-1].first + (rest == 0 ? 0 : partialSum[rest - 1].first)), y1y + (total * partialSum[n-1].second + (rest == 0 ? 0 : partialSum[rest - 1].second)), x2x, y2y) <= m){
			posRes = m;
			r = m-1;
		}
		else{
			l = m+1;
		}
	}

	cout << posRes << etr;

	return 0;
}