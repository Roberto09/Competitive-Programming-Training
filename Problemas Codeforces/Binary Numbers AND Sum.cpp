#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
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
#define MOD 998244353
#define etr "\n"
#define INF 10E10

int main(){
	sync;
	ll al, bl; cin >> al >> bl;
	bool a[al], b[bl];
	char x;
	FOR(i, 0, al){
		cin >> x;
		if(x == '1') a[i] = true;
		else a[i] = false;
	}

	FOR(i, 0, bl){
		cin >> x;
		if(x == '1') b[i] = true;
		else b[i] = false;
	}

	ll actualAccum = 0;
	ll currElevation = 1;
	ll lastBest = 0;
	FOR(i, 0, bl){
		if(i < al && a[al-i-1])
			lastBest = (currElevation + lastBest) % MOD;
		if(b[bl-i-1]){
			actualAccum = (actualAccum + lastBest) % MOD;
		}
		currElevation <<= 1;
		currElevation %= MOD;
	}
	cout << actualAccum % MOD << etr;
	return 0;
}