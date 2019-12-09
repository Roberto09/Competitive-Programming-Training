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
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); ////cout.tie(NULL)
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
#define INF 1E18

ll n, q;

//   group - number
bool mtrx[105][105];
ll matches[105];
bool seen[105];

bool check(ll nde){
	//try every group
	FOR(i, 0, n){
		if(mtrx[i][nde] && !seen[i]){
			seen[i] = true;
			if(matches[i] < 0 || check(matches[i])){
				matches[i] = nde; return true;
			}
		}
	}
	return false;
}

bool solveQ(){
	vi toDo;
	ll a; cin >> a;
	FOR(i, 0, a){
		ll b;
		cin >> b;
		toDo.pb(b);
	}

	mem(matches, ll(-1));
	ll cnt = 0;
	for(auto opt : toDo){
		if(cnt == a) break;
		mem(seen, false);
		if(check(opt)) cnt ++;
	}
	if(cnt != a) return false;

	if(a != n) toDo.pb(0);
	//try to assign every missing group to someone
	FOR(i, 0, n){
		if(matches[i] < 0){
			bool can = false;
			for(auto opt : toDo){
				if(mtrx[i][opt]){
					can = true; break;
				}
			}
			if(!can) return false;
		}
	}

	return true;
}

int main(){
	sync;
	cin >> n >> q;
	FOR(i, 0, n){
		ll a;
		cin >> a;
		FOR(j, 0, a){
			ll b;
			cin >> b; mtrx[i][b] = true;
		}
		if(a!=n) mtrx[i][0] = true;
	}

	FOR(i, 0, q){
		if(solveQ()) cout << "Y" << etr;
		else cout << "N" << etr;
	}
	return 0;
}

/*
4 3
1 2
4 2 1 3 4
1 1
4 2 1 3 4
1 3
3 1 2 3
0
*/