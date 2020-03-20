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

ll n, m ,q;

bool sts[505][505];
ll mx[505];

void calc(ll r){
	ll currmx = 0;
	ll curr = 0;
	FOR(i, 0, m+1){
		if(sts[r][i]){
			curr ++;
		}
		else{
			currmx = max(currmx, curr);
			curr = 0;
		}
	}
	mx[r] = currmx;
}


ll getMx(){
	ll rs = 0;
	FOR(i, 0, n) rs = max(mx[i], rs);
	return rs;
}

int main(){
	sync;
	cin >> n >> m >> q;
	FOR(i, 0, n){
		FOR(j, 0, m){
			ll x;
			cin >> x;
			sts[i][j] = (x == 1);
		}
	}

	FOR(i,0 , n){
		calc(i);
	}


	FOR(i, 0, q){
		ll a, b;
		cin >> a >> b; a--, b--;
		sts[a][b] = !sts[a][b];
		calc(a);
		cout << getMx() << etr;
	}


	return 0;
}