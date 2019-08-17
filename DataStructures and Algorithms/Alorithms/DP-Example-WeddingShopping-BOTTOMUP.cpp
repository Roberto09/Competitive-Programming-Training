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

bool dp[25][205];
ll prices[25][25];
ll m, a, k, p;

void iterativeDp(){
	//dp -> la nth row representa el asset que estamos evaluando mientras que la nth column representa el dinero que nos queda en ese asset
	dp[0][m] = true;

	FOR(asset, 0, a){ // por cada asset  O(assets) -> O(20)
		FOR(money, 0, m+1){ // por cada remaingin money o(money) -> O(201)
			if(dp[asset][money]) { // si podemos llegar a esa cantidad en el anterior (en este caso se deja el asset normal y no se le resta 1 ya que la row 0 tiene el money inicial)
				FOR(price, 1, prices[asset][0] + 1){ // O(prices) -> O(20)
					ll possibleMoney =  money - prices[asset][price];
					if(possibleMoney >= 0)
						dp[asset+1][possibleMoney] = true;
				}
			}
		}
	}
	FOR(money, 0, m+1){
		if(dp[a][money]){
			cout << m - money << etr;
			return;
		}
	}
	cout << "no solution" << etr;
}

void doAlg(){
	FOR(r, 0, 25){
		FOR(c, 0, 205)	dp[r][c] = false;
	}
	FOR(r, 0, 25){
		FOR(c, 0, 25)	prices[r][c] = 0;
	}

	cin >> m >> a;
	FOR(i, 0, a){
		cin >> k;
		prices[i][0] = k;
		FOR(j, 1, k+1){
			cin >> p;
			prices[i][j] = p;
		}
	}

	iterativeDp();
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