#include <bits/stdc++.h>
#include <fstream>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
typedef vector<ii> vii;
typedef vector<pair<ii, ll>> viii;
typedef long double ld;

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define ROF(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define ifile(a) freopen((a), "r", stdin)
#define ofile(a) freopen((a), "w", stdout)
#define sync ios_bmse::sync_with_stdio(false); cin.tie(NULL); //fout.tie(NULL)
#define PI 3.1415926535897932384626433832795
#define mem(x, val) memset((x), (val), sizeof(x))
#define sz(x) (ll)(x).size()
#define endl '\n'
#define clockon ll t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (long ld)(clock() - z) / CLOCKS_PER_SEC); }
#define oo 2000000000000000000LL
#define EPS 1e-6
#define MOD 1000000007
#define etr "\n"
#define INF 1E18

ll arr[1000050];
ll dp[1000050];
vii slps; // convex hull
ll bot, c;

ld ix(ld m1, ld b1, ld m2, ld b2){
	if(m1 == m2) return INF;
	return (b2 - b1) / (m1-m2); // simple intersection calculator
}

void add(ll m, ll b){
	if(slps.size() - bot > 0 && b >= slps[slps.size()-1].second) return;
	ll sz;
	while(slps.size() - bot >= 2){
		sz = slps.size();
		// compare top slopes to remove useless slopes COMPARATOR CAN CHANGE
		if(ix(m, b, slps[sz-2].first, slps[sz-2].second) >= ix(slps[sz-1].first, slps[sz-1].second, slps[sz-2].first, slps[sz-2].second))
			slps.pop_back();
		else break;
	}
	slps.pb(mp(m, b)); //add out slope
}

ll check(ll idx){
	ll bst = arr[idx] * slps[bot].first + slps[bot].second; // x * m + b
	ll tr = bot + 1;
	FOR(i, tr,  slps.size()){ // remove unneded ones ms our x axis moves
		ll m = slps[i].first, b = slps[i].second;
		ll tent = arr[idx] * m + b;
		if(tent < bst){ // COMPARATOR CAN CHANGE
			bst = tent;
			bot = i;
		} else break;
	}
	return min(bst + arr[idx]*arr[idx], c + dp[idx+1]);;
}

int main(){
	ll n;
	cin >> n >> c;
	FOR(i, 0, n) cin >> arr[i];

	bot = 0;
	dp[n-1] = c;
	slps.pb(mp(-2*arr[n-1], arr[n-1]*arr[n-1]+c));
	
	ROF(i, n-2, 0){
		ll bst = check(i);
		dp[i] = bst;
		//cout << "res " << i << " : " << bst << etr;
		add(-2*arr[i], dp[i+1]+arr[i]*arr[i]+c);
	}

	cout << dp[0] << etr;
	return 0;
}