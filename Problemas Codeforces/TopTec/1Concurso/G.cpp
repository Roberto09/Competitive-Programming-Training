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
#define INF 1E17

ll calcDist(ll a, ll b){
	if(a == b) return 1;
	if(a == 0) return 2;
	if(a == 1){
		if(b == 2 || b == 4) return 3;
		else return 4;
	}
	else if(a == 2){
		if(b == 1 || b == 3) return 3;
		else return 4;
	}
	else if(a == 3){
		if(b == 2 || b == 4) return 3;
		else return 4;
	}else{
		if(b == 1 || b == 3) return 3;
		else return 4;
	}
}

ll getBest(ll left, ll right, ll dp[][5][5], vi &arr, ll curr){
	if(curr == arr.size()) return 0;
	
	if(dp[curr][right][left] != -1) return dp[curr][right][left];
	//mover der
	ll moveRight = calcDist(right, arr[curr]) + getBest(left, arr[curr], dp ,arr, curr+1);;
	//mover izq
	ll moveLeft = calcDist(left, arr[curr]) + getBest(arr[curr], right, dp, arr, curr+1);
	return dp[curr][right][left] = min(moveRight, moveLeft);
}

int main(){
	ll n;
	while(true){
		cin >> n;
		ll counter = 0;
		if(n == 0) break;
		vector<ll> arr;
		arr.pb(n);

		while(true){
			cin >> n;
			if(n == 0) break;
			arr.pb(n);
		}
		ll dp[arr.size()][5][5];
		mem(dp, -1);
		cout << getBest(0, 0, dp, arr, 0) << etr;
	}

	return 0;
}