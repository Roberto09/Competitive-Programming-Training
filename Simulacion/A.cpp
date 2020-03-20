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
#define INF 1E15

const ll MAX = 26;
const ll MAX_N = 26;

ll T, n, k;
string s;
string arr[26];
ll mtrxA[26][26];
ll mtrxB[26][26];
ll auxmtrx[26][26];


// store result in a
void multiplyM(ll a[MAX_N][MAX_N], ll b[MAX_N][MAX_N]){
	ll auxm[MAX_N][MAX_N];
	FOR(i, 0, MAX_N){
		FOR(j, 0, MAX_N) auxm[i][j] = 0;
	}

	FOR(i, 0, MAX_N){
		FOR(j, 0, MAX_N){
			FOR(k, 0, MAX_N){
				auxm[i][j] = (auxm[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
			}
		}
	}

	FOR(i, 0, MAX_N){
		FOR(j, 0, MAX_N) a[i][j] = auxm[i][j];
	}
}

// stores result in auxmtrx
void fPMtrx(ll a[MAX_N][MAX_N], ll b, ll ret[MAX_N][MAX_N]){
    while(b > 0){
        if(b&1) multiplyM(ret, a);
        multiplyM(a, a);
        b >>= 1;
    }
}


void solve(){
	FOR(i, 0, 26){
		mtrxB[i][0] = 0;
		FOR(j, 0, 26){
			if(i == j){
				auxmtrx[i][j] = 1;
				mtrxA[i][j] = 1;
			}
			else{
				mtrxA[i][j] = 0;
				auxmtrx[i][j] = 0;
			}
		}
	}
	for(char c : s) mtrxB[c-'a'][0] ++;
	FOR(i, 0, k){
		char c;
		string w;
		cin >> c >> w;
		mtrxA[c-'a'][c-'a'] = 0;
		for(char cc : w){
			mtrxA[cc-'a'][c-'a'] ++;
		}
	}

	fPMtrx(mtrxA, n, auxmtrx);

	multiplyM(auxmtrx, mtrxB);
	ll res = 0;
	FOR(i,0, 26)
		res = (res + auxmtrx[i][0]%MOD)%MOD;
	res %= MOD;
	cout << res << etr;
}

int main(){
	sync;
	cin >> T;
	FOR(i, 0, T){
		cin >> s;
		cin >> k >> n;
		solve();
	}

	return 0;
}