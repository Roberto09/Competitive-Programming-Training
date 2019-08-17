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

ll n;
ii arr[200010];
bool app[200010];
ll getNext(ll curr){
	ll n1 = arr[curr].first, n2 = arr[curr].second;
	if((arr[n1].first == n2 || arr[n1].second == n2) && !app[n1]){
		return n1;
	}
	return n2;
}

int main(){
	sync;
	cin >> n;
	ll f, w;
	FOR(i, 1, n+1){
		cin >> arr[i].first >> arr[i].second;
		app[i] = false;
	}

	ll curr = 1;
	FOR(i, 0, n){
		cout << curr << " ";
		app[curr] = true;
		curr = getNext(curr);
	}
	return 0;
}