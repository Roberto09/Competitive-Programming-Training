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

ll A[200010];

ll B[200010];

int main(){
	ll n;
	cin >> n;
	FOR(i, 0, n) cin >> A[i];
	FOR(i, 0, n) cin >> B[i];
	unordered_map<ll, ll> posInB;
	FOR(i, 0, n) posInB[B[i]] = i;

	ll firstIdx = 0;
	//quitamos los previamente ordenados
	FOR(i, 0, n){
		if(A[i] != B[i]) break;
		firstIdx ++;
	}

	if(firstIdx == n){
		cout << 0 << etr;
		return 0;
	}

	//revisamos ascendencia
	ll res = (n - firstIdx) - 1;
	ll bar = posInB[A[firstIdx]];
	FOR(i, firstIdx+1, n){
		if(posInB[A[i]] > bar){
			res --;
			bar = posInB[A[i]];
		}
		else break;
	}
	cout << res << etr;

	return 0;
}