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

ll n, m;

struct Node{
	vector<ll> here;
	ll minDist;
};

Node arr[5005];

void precalculate(){
	FOR(i, 1 , n+1){
		Node &c = arr[i];
		ll minInt = INF;
		if(c.here.size() == 0) c.minDist = 0;
		else{
			c.minDist = (c.here.size() - 1) * n;
			FOR(j, 0, c.here.size()){
				ll dist = c.here[j] - i;
				if(dist < 0) dist += n;
				minInt = min(minInt, dist);
			}
			c.minDist += minInt;
		}
	}
}


int main(){
	cin >> n >> m;

	ll a, b;
	FOR(i, 0, m){
		cin >> a >> b;
		arr[a].here.pb(b);
	}

	precalculate();

	FOR(i, 0, n){
		ll bestRes = -INF;
		FOR(j, 0, n){
			ll currIdx = (i + j) % n + 1;
			bestRes = max(bestRes, arr[currIdx].minDist + (arr[currIdx].minDist == 0 ? 0 : j));
		}
		cout << bestRes << " ";
	}

	return 0;
}