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

ll n; 
ll arr[1505], psums[1505];

unordered_set<ll> opt;
unordered_map<ll, set<ll>> psm;


int main(){
	sync;
	cin >> n;
	ll sm = 0;
	psm[0].insert(-1);
	FOR(i, 0, n){
		cin >> arr[i];
		sm += arr[i];
		psums[i] = sm;
		psm[sm].insert(i);
	}
	unordered_map<ll, vii> prs;


	ll k, t; k = t = 0;

	FOR(i, 0, n){
		ll smm= 0;
		ROF(j, i, 0){
			smm += arr[j];
			if(prs.count(smm)){
				ii lst = prs[smm][prs[smm].size() - 1];
				if(j > lst.second){
					prs[smm].pb(mp(j, i));		
				}
			}
			else{
				prs[smm].pb(mp(j, i));
			}
			if(prs[smm].size() > t){
				t = prs[smm].size();
				k = smm;
			}
		}
	}

	cout << t << etr;
	for(ii pr : prs[k]){
		cout << pr.first+1 << " " << pr.second+1 << etr;
	}

	return 0;
}