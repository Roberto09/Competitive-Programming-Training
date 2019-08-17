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

struct day{
	string s;
	vector<ll> onePos;
	vector<ll> bestChoose;
};

ll n, m, k;
day arr[505];

void proccess(ll idx){
	day &d = arr[idx];
	FOR(i, 0, m){
		if(d.s[i] == '1') d.onePos.pb(i);
	}
	FOR(kth, 0, min(k+1, (ll)d.onePos.size())){
		d.bestChoose.pb(INF);
		FOR(i, 0, kth+1){
			ll left = d.onePos[i];
			ll right = d.onePos[d.onePos.size()-1 - (kth - i)];
			d.bestChoose[kth] = min(d.bestChoose[kth], right - left + 1);
		}
	}
	if(k >= d.onePos.size())
	d.bestChoose.pb(0);
}

//    k    n
ll dp[505][505];


ll bestAns(ll currK, ll lev){
	if(currK < 0) return INF;
	if(lev == n) return 0;
	if(dp[currK][lev] != -1) return dp[currK][lev];
	ll best = INF;
	FOR(i, 0, arr[lev].bestChoose.size()){
		ll opt = bestAns(currK - i, lev+1);
		if(opt != INF)
			best = min(best, opt + arr[lev].bestChoose[i]);
	}
	return dp[currK][lev] = best;
}

int main(){
	cin >> n >> m >> k;
	mem(dp, -1);
	FOR(i, 0, n){
		cin >> arr[i].s;
		proccess(i);
	}

	cout << bestAns(k, 0) << etr;
	return 0;
}