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
#define INF 1E9
#define MAX_N 2

ll mtrxA[MAX_N][MAX_N];
ll mtrxB[MAX_N][MAX_N];
ll auxmtrx[MAX_N][MAX_N];

//for fibonacci
void setValues(){
	mtrxA[0][0] = mtrxA[0][1] = mtrxA[1][0] = 1;
	mtrxB[0][0]= 1;
	FOR(i, 0, MAX_N) auxmtrx[i][i] = 1;
}

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

ll getRes(ll n){
	setValues();
	if(n <= 2) return mtrxB[n-1][0];
	fPMtrx(mtrxA, n-2, auxmtrx);
	multiplyM(auxmtrx, mtrxB);
	return auxmtrx[0][0];
}

int main(){
	cout << "fibonacci no 3 is: " << getRes(3);
	return 0;
}
