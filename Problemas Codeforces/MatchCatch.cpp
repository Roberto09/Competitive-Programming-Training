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
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); //////cout.tie(NULL)
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
#define INF 1E15

ll preSuArr[5050];

void suff(string &a){
	preSuArr[0] = 0;
	ll prev = 0;
	FOR(i, 1, a.length()){
		while(a[i] != a[prev] && prev > 0) prev = preSuArr[prev-1];

		if(a[i] == a[prev]){
			prev ++;
			preSuArr[i] = prev;
		}
		else preSuArr[i] = 0;
	}
}

ll getBound(string &a, string &b, ll startIdx){
	ll mx = 0;
	ll prev = 0;
	FOR(i, 0, b.length()){
		while(b[i] != a[prev] && prev > 0)	prev = preSuArr[prev-1];
		if(i == startIdx && prev == 0) continue;
		if(b[i] == a[prev]) prev ++;
		mx = max(mx, prev);
		if(prev >= a.length()){
			prev = preSuArr[prev-1];
		}
	}
	return mx + 1;
}

ll getBest(string &a, string &b, ll bound){
	ll arr[a.length()+1];
	mem(arr, ll(0));

	ll prev = 0;
	FOR(i, 0, b.length()){
		while(b[i] != a[prev] && prev > 0)	prev = preSuArr[prev-1];
		if(b[i] == a[prev]) prev ++;

		if(prev >= bound){
			arr[prev] ++;
		}

		if(prev >= a.length()){
			prev = preSuArr[prev-1];
		}
	}

	FOR(i, bound, a.length()+1){
		if(arr[i] == 1) return i;
	}

	return -1;
}

int main(){
	sync;
	string a, b;
	cin >> a >> b;

	ll res = INF;

	FOR(i, 0, a.length()){
		string opt = a.substr(i);
		suff(opt);
		ll optn = getBound(opt, a, i);
		ll o = getBest(opt, b, optn);
		if(o > -1)
			res = min(o, res);
	}
	if(res == INF) cout << -1 << etr;
	else cout << res << etr;
	return 0;
}


