#include <bits/stdc++.h>
#include <fstream>
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
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); //fout.tie(NULL)
#define PI 3.1415926535897932384626433832795
#define mem(x, val) memset((x), (val), sizeof(x))
#define sz(x) (ll)(x).size()
#define endl '\n'
#define clockon ll t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (long long double)(clock() - z) / CLOCKS_PER_SEC); }
#define oo 2000000000000000000LL
#define EPS 1e-6
#define MOD 1000000007
#define etr "\n"
#define INF 1E18

ll bot;
vii slps;
ll n;
vector<pair<ii, ll>> rects;

long double ix(long double m1, long double b1, long double m2, long double b2){
	if(m1 == m2) return INF;
	return (b2 - b1) / (m1-m2);
}

void add(ll idx){
	ll m = -rects[idx].first.first;
	ll b = rects[idx].second;
	if(slps.size() - bot > 0 && b <= slps[slps.size()-1].second) return;
	while(slps.size() - bot >= 2){
		if(ix(m, b, slps[slps.size()-2].first, slps[slps.size()-2].second) >= ix(slps[slps.size()-1].first, slps[slps.size()-1].second, slps[slps.size()-2].first, slps[slps.size()-2].second)){
			slps.pop_back();
		}
		else break;
	}
	slps.pb(mp(m, b));
}

ll check(ll idx){
	ll x = rects[idx].first.second;
	ll bst = x * slps[bot].first + slps[bot].second;
	ll tr = bot + 1;
	FOR(i, tr,  slps.size()){
		ll m = slps[i].first, b = slps[i].second;
		ll tent = x * m + b;
		if(tent > bst){
			bst = tent;
			bot = i;
		} else break;
	}
	// consider yourself as well
	return max(bst + rects[idx].second, rects[idx].second);
}

int main(){
	sync;
	cin >> n;
	FOR(i, 0, n){
		ll x, y, c;
		cin >> x >> y >> c;
		rects.pb(mp(mp(x, y), x*y - c));
	}
	sort(rects.begin(), rects.end());

	ll bot = 0;
	ll res = max(0ll, rects[0].second);
	add(0);
	FOR(i, 1, n){
		ll opt = check(i);
		res = max(opt, res);
		rects[i].second = opt;
		add(i);
	}
	cout << res << etr;

	return 0;
}	
/*
9
12 8 8
9 10 37
4 14 7
15 4 41
7 11 64
2 16 4
16 1 7
14 5 57
6 12 26
*/