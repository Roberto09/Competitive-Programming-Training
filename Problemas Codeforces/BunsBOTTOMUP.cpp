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

struct stuffing{
	ll stuffCant, stuffReq, dReq, sellPrice;
};

stuffing stuffings[15];
ll dough, n;

ll dp[15][1005];

ll casoIterativo(){
	ll maxMoney = 0;
	FOR(sf, 0, n){ // por cada stuffing
		FOR(d, 0, 1005){ //por cada cantidad de masa
			ll money = dp[sf][d];
			if (money != -1){ // si se pudo producir x cantidad de dinero con el stuffing anterior
				stuffing &curr = stuffings[sf];
				FOR(i, 0, min(curr.stuffCant/curr.stuffReq, d/curr.dReq)+1){//por cada cantidad posible de panes a producir con dicho stuffing
					dp[sf+1][d - (i * curr.dReq)] = max(money + i * curr.sellPrice, dp[sf+1][d - (i * curr.dReq)]);
					maxMoney = max(dp[sf+1][d - (i * curr.dReq)], maxMoney);
				}
			}
		}
	}
	return maxMoney;
}

int main(){
	sync;
	cin >> dough >> n;
	n++;
	stuffings[0].stuffCant = INF;
	stuffings[0].stuffReq = 1;
	cin >> stuffings[0].dReq >> stuffings[0].sellPrice;
	FOR(i, 1, n){
		cin >> stuffings[i].stuffCant >> stuffings[i].stuffReq >> stuffings[i].dReq >> stuffings[i].sellPrice;	
	}
	FOR(i, 0, n+1){
		FOR(j, 0, 1005) dp[i][j] = -1;
	}
	dp[0][dough] = 0;
	cout << casoIterativo() << etr;
	return 0;
}