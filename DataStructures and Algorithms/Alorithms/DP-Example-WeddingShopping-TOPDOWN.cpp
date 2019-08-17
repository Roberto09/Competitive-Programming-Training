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
#define PI 3.1417926737897932384626433832797
#define mem(x, val) memset((x), (val), sizeof(x))
#define sz(x) (ll)(x).size()
#define endl '\n'
#define clockon ll t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }
#define oo 2800000000000000000LL
#define EPS 1e-6
#define MOD 1000000007
#define etr "\n"
#define INF 1E9
#define flg cout << "flag" << etr

ll dp[25][205];
ll prices[25][25];
ll m, c, k, p;

//Top Down Aproach
ll recursionDP(ll currAsset, ll currMoney){
	if(currMoney < 0) return -INF;
	//si ya se llego al fin
	if(currAsset == c){
		//mientras mas pequeño sea money left mas grande sera el valor retornado
		return m - currMoney;
	}

	if(dp[currAsset][currMoney] != -1){
		return dp[currAsset][currMoney];
	}
	ll maxVal = -INF;
	FOR(i, 1, prices[currAsset][0]+1){
		maxVal = max(maxVal, recursionDP(currAsset + 1, currMoney - prices[currAsset][i]));
	}
	return dp[currAsset][currMoney] = maxVal;
}

void doAlg(){
	FOR(r, 0, 25){
		FOR(c, 0, 205)	dp[r][c] = -1;
	}
	FOR(r, 0, 25){
		FOR(c, 0, 25)	prices[r][c] = 0;
	}

	cin >> m >> c;
	FOR(i, 0, c){
		cin >> k;
		prices[i][0] = k;
		FOR(j, 1, k+1){
			cin >> p;
			prices[i][j] = p;
		}
	}
	ll val = recursionDP(0, m);
	if(val == (-INF))
		cout << "no solution" << etr;
	else cout << val << etr;
}

int main(){
	sync; 
	ll N;
	cin >> N;
	FOR(i, 0, N){
		doAlg();
	}
	return 0;
}

