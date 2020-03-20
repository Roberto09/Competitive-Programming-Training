#include <bits/stdc++.h>
#include <fstream>
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
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); //fout.tie(NULL)
#define PI 3.1415926535897932384626433832795
#define mem(x, val) memset((x), (val), sizeof(x))
#define sz(x) (ll)(x).size()
#define endl '\n'
#define clockon ll t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (long double)(clock() - z) / CLOCKS_PER_SEC); }
#define oo 2000000000000000000LL
#define EPS 1e-6
#define MOD 1000000007
#define etr "\n"
#define INF 10E18

ll as[100050], bs[100050];

ll dp[100050];

ll bot;

vii slps;

double ix(double m1, double b1, double m2, double b2){
	return (b2 - b1) / (m1-m2);
}

void add(ll m, ll b){
	while(slps.size() - bot >= 2){
		if(ix(m, b, slps[slps.size()-2].first, slps[slps.size()-2].second) < ix(slps[slps.size()-1].first, slps[slps.size()-1].second, slps[slps.size()-2].first, slps[slps.size()-2].second)){
			slps.pop_back();
		}
		else break;
	}
	slps.pb(mp(m, b));
}

ll check(ll idx){
	ll bst = bs[idx] * slps[bot].first + slps[bot].second;
	ll tr = bot + 1;
	FOR(i, tr,  slps.size()){
		ll m = slps[i].first, b = slps[i].second;
		ll tent = bs[idx] * m + b;
		if(tent < bst){
			bst = tent;
			bot = i;
		} else break;
	}
	return bst;
}

int main(){
	ll n;
	cin >> n;
	FOR(i, 0, n){
		cin >>as[i];
	}
	FOR(i, 0, n){
		cin >> bs[i];
	}


	//ll rm = n-1;
	bot = 0;
	slps.pb(mp(as[n-1], 0));

	ROF(i, n-2, 0){
		ll bst = check(i);
		dp[i] = bst;
		add(as[i], bst);
	}

	//FOR(i,0, n) cout << dp[i] << " ";
	//cout << etr;
	cout << dp[0] << etr;

	return 0;
}