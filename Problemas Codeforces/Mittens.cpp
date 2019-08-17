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
6 3
1 3 2 2 1 1
*/

ll n, m;

vii res;

ii arr[110];
ii arr2[110];
ll cnt = 0;

int main(){
	cin >> n >> m;
	FOR(i, 0, m){
		arr[i].second = i, arr[i].first = 0;
		arr2[i].second = i, arr2[i].first = 0;
	}
	ll x;
	FOR(i, 0, n){
		cin >> x; x--;
		arr[x].first ++;
		arr2[x].first ++;
	}

	sort(arr, arr + m, greater<ii>());
	sort(arr2, arr2 + m, greater<ii>());

	ll left = 0; ll right = 1;

	while(right < m){
		ii &l = arr[left], &r = arr2[right];
		if(l.first == 0){
			left ++; continue;
		}
		if(r.first == 0){
			right ++; continue;
		}
		l.first --; r.first --;
		res.pb(mp(l.second+1, r.second+1));
		if(l.second != r.second) cnt ++;
	}

	ll nleft = m-1, nright = 0;
	while(nleft >= left){
		ii &l = arr[nleft], &r = arr2[nright];
		if(l.first == 0){
			nleft --; continue;
		}
		if(r.first == 0){
			nright --; continue;
		}
		l.first --; r.first --;
		res.pb(mp(l.second+1, r.second+1));
		if(l.second != r.second) cnt ++;	
	}

	cout << cnt << etr;
	FOR(i, 0, res.size()) cout << res[i].first << " " << res[i].second << etr;
	return 0;
}