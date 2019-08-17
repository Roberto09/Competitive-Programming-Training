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
ll arr[100000];
ll n, k, A, B;

ll dif(ll a, ll b){
	ll l, r, m;
	r = k-1; l = 0;
	ll upd1 = -10;
	while(l <= r){
		m = l +(r-l) / 2;
		if(arr[m] >= a){
			upd1 = m-1;
			r = m-1;
		}
		else{
			l = m+1;
		}
	}

	ll upd2 = -10;
	r = k-1; l = 0;
	while(l <= r){
		m = l +(r-l) / 2;
		if(arr[m] <= b){
			upd2 = m+1;
			l = m+1;
		}
		else{
			r = m-1;
		}
	}
	//cout << upd1 << "  " << upd2 << etr;
	if(upd2 == -10 || upd1 == -10) return -1; 
	return (upd2 - upd1) - 1;
}

ll calculate(ll ax, ll bx){
	ll df = dif(ax, bx);
	if(df <= 0) return A;
	//cout << ax << " " << bx << etr;
	//cout << "df: " << df << etr;
	ll burnHere = df * B * ((bx - ax) + 1);
	//cout << "burnHere: " << burnHere << etr;
	if(ax == bx) return burnHere;
	ll burnSns = calculate(ax, (ax + bx) / 2) + calculate((ax + bx) / 2 + 1, bx);
	return min(burnHere, burnSns);
}

int main(){
	cin >> n >> k >> A >> B;
	FOR(i, 0, k) cin >> arr[i];
	sort(arr, arr + k);
	cout << calculate(1, pow(2, n)) << etr;
	return 0;
}