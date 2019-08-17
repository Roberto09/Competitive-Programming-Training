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
#define INF 1E10


struct caso{
	bool type;
	ll fs;
};

ll n;
ll dp[5010][5010];

ll casoIndividual(ll idx, vector<caso> &casos, ll idLevels){
	if(idx == n) return 1;
	caso &c = casos[idx];
	ll sum = 0;
	//si es una s
	if(dp[idx][idLevels] != -1) return dp[idx][idLevels];
	if(c.type){
		FOR(i, 1, idLevels+1){
			sum += (casoIndividual(idx +1, casos, i) % MOD);
			sum %= MOD;
		}
	}
	//si no es un a s
	else{
		FOR(i, 1, idLevels+1){
			sum += (casoIndividual(idx + 1, casos, i + c.fs) % MOD);
			sum %= MOD;
		}
	}
	dp[idx][idLevels] = sum%MOD;
	return (sum%MOD);
}


int main(){
	sync;
	cin >> n;

	FOR(i, 0, 5010){
		FOR(j, 0, 5010){
			dp[i][j] = -1;
		}
	}

	vector<caso> casos;
	
	char c;
	bool hasPrevF = false;
	ll prevF = 0;
	FOR(i, 0, n){
		cin >> c;
		if(c == 's'){
			caso cs;
			if(hasPrevF){
				cs.type = false;
				cs.fs = prevF;
				casos.pb(cs);
			}
			else{
				cs.type = true;
				casos.pb(cs);
			}
			hasPrevF = false;
			prevF = 0;
		}
		else{
			if(hasPrevF){
				prevF ++;
			}
			else{
				hasPrevF = true;
				prevF = 1;
			}
		}
	}

	n = casos.size();
	cout << casoIndividual(0, casos, 1) << etr;

	return 0;
}