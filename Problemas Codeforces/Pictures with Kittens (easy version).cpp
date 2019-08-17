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
ll n, k, x;
ll levels;

ll arr[1005]; // numbrs
ll intersects[1005]; //numbrs
bool isIntersected[1005]; //levels

    //curr xs  selection factor
ll dp[1005][1005][1005];

ll canCauseDp[1005];

bool checkValidity(ll curr){
	if(curr >= k-1){
		return isIntersected[curr-(k-1)];
	}
	return true;
}

void makeCurrIntersections(ll curr, vi &currIntersecions){
	ll lastLevel, firstLevel;
	if(curr < levels) lastLevel = curr;
	else lastLevel = levels-1;

	firstLevel = lastLevel - (intersects[curr] - 1);
	FOR(i, firstLevel, lastLevel+1){
		if(isIntersected[i]) continue;
		isIntersected[i] = true;
		currIntersecions.pb(i);
	}
}

ll calcItnersectionFactor(ll prevNmbr){
	ll curr = prevNmbr+1;
	if(curr == n) return 0;

	ll lastLevel, firstLevel;
	if(prevNmbr < levels) lastLevel = prevNmbr;
	else lastLevel = levels-1;
	firstLevel = lastLevel - (canCauseDp[prevNmbr]) + 1;

	ll res = 0;
	FOR(i, firstLevel, lastLevel+1){
		if(isIntersected[i]) res ++;
	}
	return res;
}

ll getBest(ll curr, ll xsLeft, ll selectionFactor){
	//2 opciones
	//casos base
	if(curr == n){
		if(xsLeft == 0) return 0;
		return -INF;
	}
	if(xsLeft < 0) return -INF;

	if(dp[curr][xsLeft][selectionFactor] != INV) return dp[curr][xsLeft][selectionFactor];

	ll use = -INF, notUse = -INF;
	bool forcedToUse = !checkValidity(curr);

	//usar
	//marcamos los niveles nuevos utilizados
	vi currIntersecions;
	makeCurrIntersections(curr, currIntersecions);
	//calculamos el intersectionFactor
	ll intersectionFactorUse = calcItnersectionFactor(curr);
	use = getBest(curr+1, xsLeft-1, intersectionFactorUse);

	FOR(i, 0, currIntersecions.size()) isIntersected[currIntersecions[i]] = false;

	//no usar
	if(!forcedToUse)
		notUse = getBest(curr+1, xsLeft, calcItnersectionFactor(curr));

	ll retVal;
	//retorno el mayor
	if(use == -INF && notUse == -INF) retVal = -INF;
	else if(use == -INF) retVal = notUse;
	else retVal = max(use+arr[curr], notUse);
	//return dp[curr][xs][intersected] = retVal;
	return dp[curr][xsLeft][selectionFactor] = retVal;
}

void calculateIntersections(){
	FOR(i, 0, n){
		intersects[i] = k;
		isIntersected[i] = false;
	}
	FOR(i, 0, k-1)
		intersects[i] = intersects[n-i-1] = i+1;

	FOR(i, 0, n-1) canCauseDp[i] = k-1;
	FOR(i, 0, k-2) canCauseDp[i] = canCauseDp[n-i-2] = i+1;

	FOR(i, 0, n+1){
		FOR(j, 0, x+2){
			FOR(k, 0, n+1){
				dp[i][j][k] = INV;
			}
		}
	}
}

int main(){
	sync;
	cin >> n >> k >> x;
	FOR(i, 0, n) cin >> arr[i];
	calculateIntersections();
	levels = n-k+1;
	ll res = getBest(0, x, 0);
	if(res == -INF) cout << -1 << etr;
	else cout << res << etr;
	return 0;
}