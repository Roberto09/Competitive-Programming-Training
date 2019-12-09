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

ll preSuArr[1000050];

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

string kmp(string &a, string &b, ll strt){
	ll prev = 0;
	FOR(i, strt, b.length()){
		while(b[i] != a[prev] && prev > 0)	prev = preSuArr[prev-1];
		if(b[i] == a[prev]) prev ++;
		if(prev >= a.length()){
			if(i == b.length() -1) continue;
			prev = preSuArr[prev-1];
		}
	}
	return a.substr(prev);
}

string res, a;

int main(){
	ll n;
	cin >> n;
	cin >> res;
	FOR(i, 1 , n){
		cin >> a;
		suff(a);
		ll x = max(ll(0), ll(res.length()) - ll(a.length()));
		res += kmp(a, res, x);
	}
	cout << res << etr;
	return 0;
}