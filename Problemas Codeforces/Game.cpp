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
ll depCount[205];
vi doneBefore[205];
vi room[3];

ll getRes(ll start){
	ll cnt = 0;
	ll res = n;
	
	bool visited[n];
	mem(visited, false);

	ll curr = start;
	while(cnt < n){
		vi &r = room[curr];
		bool canContinueVisiting = true;

		while(canContinueVisiting){
			canContinueVisiting = false;
			FOR(i, 0, r.size()){
				if(visited[r[i]]) continue;
				bool canVisitActual = true;
				FOR(j, 0, doneBefore[r[i]].size()){
					if(!visited[doneBefore[r[i]][j]]) canVisitActual = false;
				}
				if(canVisitActual){
					visited[r[i]] = true;
					cnt ++;
					canContinueVisiting = true;
				}
			}
		}

		res ++;
		curr ++;
		curr %= 3;
	}
	return res - 1;
}

int main(){
	cin >> n;
	ll x;
	FOR(i, 0, n){
		cin >> x;
		x --;
		room[x].pb(i);
	}

	ll a;
	FOR(i, 0, n){
		cin >> x; 
		FOR(j, 0, x){
			cin >> a;
			a--;
			doneBefore[i].pb(a);
		}
	}


	ll res = INF;
	FOR(i, 0, 3) res = min(res, getRes(i));
	cout << res << etr;

	return 0;
}