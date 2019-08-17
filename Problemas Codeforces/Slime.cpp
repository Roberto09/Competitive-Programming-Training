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
#define INF 1E9

int main(){
	sync;
	ll n;
	cin >> n;
	ll arr[n];

	bool positive = false;
	bool negative = false;


	if(n ==  1){
		cin >> arr[0];
		cout << arr[0] << etr;
		return 0;
	}

	FOR(i, 0, n){
		cin >> arr[i];
		if(arr[i] >= 0){
			positive = true;
		}
		else negative = true;
	}

	ll sum = 0;
	if(positive && negative){
		FOR(i, 0, n){
			sum += abs(arr[i]);
		}
	}
	else if(positive){
		//debemos convertir uno a negativo, el mas pequeño
		ll mn = INF;
		ll mnPos = 0;
		FOR(i, 0, n){
			if(arr[i] < mn){
				mn = arr[i];
				mnPos = i;
			}
		}
		FOR(i, 0, n){
			sum += arr[i];
		}
		sum -= (arr[mnPos] + (mnPos == n-1 ? arr[mnPos-1] : arr[mnPos+1]));
		sum += abs(arr[mnPos] - (mnPos == n-1 ? arr[mnPos-1] : arr[mnPos+1]));
	}
	else{
		//debemos convertir uno a positivo, el mas grande
		ll max = -INF;
		ll maxPos = 0;
		FOR(i, 0, n){
			if(arr[i] > max){
				max = arr[i];
				maxPos = i;
			}
		}
		FOR(i, 0, n){
			sum += abs(arr[i]);
		}
		sum += (arr[maxPos] + (maxPos == n-1 ? arr[maxPos-1] : arr[maxPos+1]));
		sum += abs(arr[maxPos] - (maxPos == n-1 ? arr[maxPos-1] : arr[maxPos+1]));
	}
	cout << sum << etr;
	return 0;
}