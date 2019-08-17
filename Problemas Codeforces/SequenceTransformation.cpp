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
#define INF 1E9;
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << '\n';
}

void solve(ll n, ll mult, vector<int> &result){
	if(n == 1){
		result.pb(mult);
		return;
	}
	if(n == 2){
		result.pb(mult);
		result.pb(mult*2);

		return;
	}
	if(n == 3){
		result.pb(mult);
		result.pb(mult);
		result.pb(mult*3);
		return;
	}
	ll fillWithMult = ceil((double) n/2);;
	FOR(i, 0, fillWithMult){
		result.pb(mult);
	}
	solve(n/2, mult*2, result);
}

int main(){
	sync;
	ll n;
	cin >> n;
	vector<int> res;
	solve(n, 1, res);
	FOR(i, 0, n){
		cout << res[i] << " ";
	}
	cout << etr;
}