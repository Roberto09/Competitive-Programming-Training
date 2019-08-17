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

ll arr[100005];

int main(){
	ll n, k;
	cin >> n >> k;
	ll mn = INF;
	ll left, right;
	FOR(i, 0, n) cin >> arr[i];
	unordered_map<ll, ll> numPos;
	set<ll> pos;
	set<ll, greater<ll>> maxPos;
	FOR(i, 0, n){
		ll nmbr = arr[i];
		if(numPos.count(nmbr)){
			pos.erase(numPos[nmbr]);
			maxPos.erase(numPos[nmbr]);
			numPos[nmbr] = i;
			pos.insert(i);
			maxPos.insert(i);
		}
		else{
			numPos[nmbr] = i;
			pos.insert(i);
			maxPos.insert(i);
		}

		if(numPos.size() == k){
			if((*maxPos.begin() - *pos.begin()) + 1 < mn){
				right = *maxPos.begin();
				left =  *pos.begin();
				mn = min(mn, (*maxPos.begin() - *pos.begin() + 1));
			}	
		}
	}
	if(mn == INF) cout << -1 << " " << -1 << etr;
	else cout << left+1 << " " << right+1 << etr;
	return 0;
}

