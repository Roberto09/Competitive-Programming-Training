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
#define INF 1E9;

struct Node{
	vi values;
	vi sums;
	ll totalSum;
};

int main(){
	sync;
	ll n, m;
	cin >> n >> m;
	unordered_map<ll, Node> arr;
	FOR(i, 0, m) arr[m].totalSum = 0;
	
	ll a, b;
	FOR(i, 0, n){
		cin >> a >> b;
		a--;
		arr[a].values.pb(b);
	}

	ll mxSize = 0;
	FOR(i, 0, m){
		mxSize = max((ll)arr[i].values.size(), mxSize);
		sort(arr[i].values.begin(), arr[i].values.end(), greater<ll>());
	}

	FOR(i, 0, m){
		ll prev = 0;
		FOR(j, 0, arr[i].values.size()){
			arr[i].sums.pb(prev + arr[i].values[j]);
			prev = arr[i].sums[j];
		}
		arr[i].totalSum = prev;
	}

	ll mx = 0;

	FOR(i, 0, mxSize){
		ll currSum = 0;
		vi toErase;
		for(auto it = arr.begin(); it != arr.end(); it ++){
			Node &curr = it->second;
			if(i >= curr.values.size() || (curr.sums[i] < 0)){				
				toErase.pb(it->first);
				continue;
			}
			currSum += curr.sums[i];
		}
		FOR(i, 0, toErase.size()) arr.erase(toErase[i]);
		mx = max(currSum, mx);
	}
	cout << mx << etr;
	return 0;
}