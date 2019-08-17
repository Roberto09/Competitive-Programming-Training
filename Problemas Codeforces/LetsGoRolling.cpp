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

ii arr[3005];
ll arrMin[3005][3005];
bool arrC[3005][3005];
ll n;
ll individualTCase(ll currIdx, ll lastClapedIdx){
	if(currIdx == n) return 0;
	if(arrC[currIdx][lastClapedIdx]) return arrMin[currIdx][lastClapedIdx];
	//clavar o no clavar
	ll clavar = individualTCase(currIdx + 1, currIdx) + arr[currIdx].second;
	ll noClavar = individualTCase(currIdx + 1, lastClapedIdx) + arr[currIdx].first - arr[lastClapedIdx].first;
	arrC[currIdx][lastClapedIdx] = true;
	return arrMin[currIdx][lastClapedIdx] = min(clavar, noClavar);
}

ll startAlg(){
	return individualTCase(1, 0) + arr[0].second;
}

int main(){
	sync;
	cin >> n;
	FOR(i, 0, n){
		cin >> arr[i].first >> arr[i].second;
	}
	FOR(i, 0, n){
		FOR(j, 0, n) arrC[i][j] = false;
	}
	sort(arr, arr+n);
	cout << startAlg() << etr;
	return 0;
}
