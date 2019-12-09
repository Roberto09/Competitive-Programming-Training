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
#define INF 1E18

ll n;
ll mn = 1000000;
unordered_set<ll> u;
unordered_set<ll> dttd;
vi uv;

int main(){
	sync;
	cin >> n;
	ll x;
	FOR(i, 0, n){
		cin >> x;
		uv.pb(x);
		u.insert(x);
		dttd.insert(x);
	}

	vi res;
	for(ll e : uv){
		if(e <= mn/2){
			if(!u.count(mn-(e-1))){
				res.pb(mn-(e-1));
				u.erase(e);
			}
		}
		else{
			if(!u.count(mn - e + 1)){
				res.pb(mn - e + 1);
				u.erase(e);
			}
		}
	}

	ll toComp = u.size() / 2;
	FOR(i, 1, mn/2 + 1){
		if(toComp == 0) break;
		if(!dttd.count(i) && !dttd.count(mn - i + 1)){
			toComp --;
			res.pb(i); res.pb(mn - i + 1);
		}
	}

	cout << res.size() << etr;
	for(ll e : res) cout << e << " ";

	return 0;
}