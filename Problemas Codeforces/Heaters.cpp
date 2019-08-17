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

ll freq[2][1048590];
bool arr[1005];

int main(){
	sync;
	ll n, k;
	cin >> n >> k;
	ll x;
	bool possible = false;
	FOR(i, 0, n){
		cin >> x;
		if(x) arr[i] = possible = true;
	}

	if(!possible){
		cout << -1 << etr;
		return 0;
	}

	k--;
	ll left = -INF, right = -1;
	ll count = 0;
	FOR(i, 0, n){
		if(arr[i]){
			if(i - k <= left){
				right = i+k;
			}
			else if(i + k > right){
				if(i-k > right+1){
					possible = false; break;
				}
				left = right+1;
				right = i+k;
				count ++;
			}
			if(right >= n-1) break;
		}
	}

	if(!possible || right < n-1){
		cout << -1 << etr;
		return 0;
	}
	cout << count << etr;
	return 0;
}
