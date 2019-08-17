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

ll l, p;
ll arr[300005];
ll positions[300005];
unordered_set<ll> cambios[300005];

ll getBest(){
	unordered_set<ll> &nastya = cambios[arr[0]];
	ll res = 0;

	ll idx;
	FOR(i, 1, l){
		idx = i;
		if(nastya.count(arr[i])) res ++;
		else break;
	}

	ll lastSetIdx = idx;
	FOR(i, idx+1, l){
		unordered_set<ll> &currSet = cambios[arr[lastSetIdx]];
		bool shouldAdd = true;
		if(nastya.count(arr[i]) && currSet.count(arr[i])){
			res ++;
			shouldAdd = false;
		}

		if(shouldAdd){
			unordered_set<ll> &pass = cambios[arr[i]];
			vi ers;
			for(auto it = pass.begin(); it != pass.end(); it ++){
				if(!currSet.count(*it)) ers.pb(*it);
			}
			FOR(j, 0, ers.size()) pass.erase(ers[j]);
			lastSetIdx = i;
		}
	}
	return res;
}

int main(){
	sync;
	cin >> l >> p;
	FOR(i, 0, l) cin >> arr[i];

	reverse(arr, arr+l);

	ll a, b;
	FOR(i, 0, p){
		cin >> a >> b;
		cambios[b].insert(a);
	}

	cout << getBest() << etr;
	return 0;
}