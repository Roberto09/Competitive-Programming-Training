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

ii arr[100005];

int main(){
	sync;
	ll n; cin >> n;
	
	ll left = 0, right = 0;
	FOR(i, 0, n){
		cin >> arr[i].first >> arr[i].second;	
		left += arr[i].first;
		right += arr[i].second;
	}
	ll bestBeauty = abs(left-right);
	ll idx = 0;
	FOR(i, 0, n){
		ll r = arr[i].second, l = arr[i].first;
		if(abs((left-l+r) - (right-r+l)) > bestBeauty){
			bestBeauty = abs((left-l+r) - (right-r+l));
			idx = i + 1;
		}
	}

	cout << idx << etr;
	return 0;
}
