
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

int main(){
	sync;
	ll n, d; 
	cin >> n >> d;
	ll arr[n+1] = {0};
	ll money[n+1] = {0};
	ll maxUpToHere[n+1] = {0};
	vi wrongCeros;
	bool wrongFromStart = false;
	FOR(i, 1, n+1){
		cin >> arr[i];
		money[i] = money[i-1] + arr[i];
		if(arr[i] == 0 && money[i] < 0) wrongCeros.pb(i);
		if(money[i] > d) wrongFromStart = true;
	}
	if(wrongFromStart){
		cout << -1 << etr;
		return 0;
	}
	if(wrongCeros.size() == 0){
		cout << 0 << etr;
		return 0;
	}

	maxUpToHere[n] = money[n];
	ROF(i, n-1, 0){
		maxUpToHere[i] = max(money[i], maxUpToHere[i+1]);
	}

	reverse(wrongCeros.begin(), wrongCeros.end());

	ll res = 0;
	ll accumulatedSum = 0;
	while(wrongCeros.size() > 0){
		ll ceroPos = wrongCeros[wrongCeros.size() - 1];
		ll toBeat = money[ceroPos] + accumulatedSum;
		if(toBeat >= 0){
			wrongCeros.pop_back();
			continue;
		}
		ll maxSum = d - (maxUpToHere[ceroPos] + accumulatedSum);
		if(maxSum + toBeat >= 0){
			res ++;
			accumulatedSum += maxSum;
			wrongCeros.pop_back();
		}
		else{
			cout << -1 << etr;
			return 0;
		}
	}

	cout << res << etr;
	return 0;
}