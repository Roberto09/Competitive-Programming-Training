#include <bits/stdc++.h>
#include <limits>
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
#define INF 1E9 + 1;

void find(){
	double n;
	cin >> n;
	if(n==0){ cout << "Y 0.00 0.00" << etr; return; }
	double l = 0, r = n, mid, a, b;
	while(l < r){
		mid = l + (r-l)/2;
		a = mid;
		b = n-mid;
		if(abs((a+b) - a*b) <= 0.000001 && abs((a+b)-n) <= 0.000001){
			cout << "Y " << std::setprecision (15) << b << " "<< a << etr;
			return;
		}
		else if(a*b > n) r = mid-0.000000000000001;
		else l = mid+0.000000000000001;
	}

	cout << "N" << etr;
}

int main(){
	sync;
	ll n;
	cin >> n;
	FOR(i, 0, n){
		find();
	}
	return 0;
}