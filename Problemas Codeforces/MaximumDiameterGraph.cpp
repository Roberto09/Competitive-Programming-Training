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

/*
5
1 4 1 1 1
*/

ll n;

int main(){
	cin >> n;
	vi ones;
	vii others;
	ll x;
	ll cnt = 0;
	FOR(i, 0, n){
		cin >> x;
		cnt += x;
		if(x == 1) ones.pb(i+1);
		else{
			x-= 2;
			others.pb(mp(i+1, x));
		}
	}

	if(cnt < (n-2) * 2 + 2){
		cout << "NO" << etr;
		return 0;
	}

	others[0].second ++;
	others[others.size()-1].second ++;

	ll diam = ones.size();
	if(diam > 2) diam = 2;
	diam += others.size();
	diam --;

	vii edges;

	FOR(i, 0, others.size()-1){
		edges.pb(mp(others[i].first, others[i+1].first));
	}

	ll left = 0, right = others.size() - 1;

	bool leftb = true;
	FOR(i, 0, ones.size()){
		if(leftb){
			while(others[left].second == 0) left ++;
			edges.pb(mp(ones[i], others[left].first));
			others[left].second --;
		}
		else{
			while(others[right].second == 0) right --;
			edges.pb(mp(ones[i], others[right].first));
			others[right].second --;
		}
		leftb = !leftb;
	}
	cout << "YES " << diam << etr;
	cout << edges.size() << etr;
	FOR(i, 0, edges.size()) cout << edges[i].first << " " << edges[i].second << etr;

	return 0;
}