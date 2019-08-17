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
#define INF 1E16
#define NV 1E17

    //curr   k    skip no skip
ll dp[5005][1050];
ll costs[5005];
ll arr[5005];
ll t;
ll n, k;

void precalccosts(){
	FOR(i, 0, n-1){
		costs[i] = (arr[i] - arr[i+1])*(arr[i] - arr[i+1]);
	}
}

void clear(){
	FOR(i, 0, n+2){
		FOR(j, 0, k+2)
			dp[i][j] = NV;
	}
}

ll getBest(ll curr, ll fee, ll actualK){
	if(actualK == k){
		if(n-curr >= fee) return 0;
		return INF;
	}
	if(curr >= n) return INF;
	if(dp[curr][actualK] != NV) return dp[curr][actualK];
	//default
	bool forced = false;
	if((k - actualK) * 3 + (fee == 0? 0 : fee-1) > n-(curr+1)) forced = true;

	ll use = INF, notUse = INF;
	//escoger
	use = costs[curr] + getBest(curr+2, fee+1, actualK+1);
	//no escoger
	if(!forced)
		notUse = getBest(curr+1, (fee == 0 ? 0 : fee-1), actualK);

	ll retVal;
	//retorno el mayor
	if(use == INF && notUse == INF) retVal = INF;
	else if(use == INF) retVal = notUse;
	else retVal = min(use, notUse);
	//return dp[curr][xs][intersected] = retVal;
	return dp[curr][actualK] = retVal;
}

int main(){
	sync;
	cin >> t;
	FOR(i, 0, t){
		cin >> k >> n;
		k += 8;
		FOR(j, 0, n) cin >> arr[j];
		precalccosts();
		clear();
		ll res = getBest(0, 0, 0);
		cout << res << etr;
	}
	return 0;
}