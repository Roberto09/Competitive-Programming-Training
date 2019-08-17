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
#define INF 1E16
#define INV -1E17

struct dpAuxO{
	ll total = 0;
	deque<ii> bests;

	void addDeque(ll nmbr){
		ll count = 0;
		while(!bests.empty()){
			if(nmbr >= bests.back().first){
				count += bests.back().second;
				bests.pop_back();
			}
			else break;
		}
		bests.pb(mp(nmbr, count+1));
		total ++;
	}
	void removeDeque(){
		bests.front().second --;
		if(bests.front().second == 0) bests.pop_front();
		total--;
	}
	ll getBest(){
		return bests.front().first;
	}
};

ll n, k, x;

ll arr[5005]; // numbrs
//    curr   x
ll dp[5005][5005];

dpAuxO dpAux[5005];

ll getBest(ll currNmbr, ll currX){
	if(currX == 1 && currNmbr < k) return dp[currNmbr][currX] = arr[currNmbr];
	else if (currX == 1 && currNmbr >= k) return dp[currNmbr][currX] = -1;
	
	if(dp[currNmbr][currX] != -INF) return dp[currNmbr][currX];

	ll best = -1;

	ll option = getBest(currNmbr - 1, currX-1);
	dpAux[currX].addDeque(option);

	if(dpAux[currX].total > k){
		dpAux[currX].removeDeque();
	}

	best = dpAux[currX].getBest();

	if(best == -1) return dp[currNmbr][currX] = -1;
	return dp[currNmbr][currX] = (best + arr[currNmbr]);
}

void clear(){
	FOR(i, 0, n+1){
		FOR(j, 0, x+1) dp[i][j] = -INF;
	}
}

ll getResult(){
	ll best = -1;
	ll option;
	FOR(i, x-1, n) {
		option = getBest(i, x);
		if(i >= n-k)
			best = max(best, option);
	}
	return best;
}

int main(){
	sync;
	cin >> n >> k >> x;
	FOR(i, 0, n) cin >> arr[i];
	clear();
	ll res = getResult();
	if(res == -INF) cout << -1 << etr;
	else cout << res << etr;
	return 0;
}