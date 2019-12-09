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

string s;
ll s2[500050];
ll hay[500050];
ll needle[500050];
ll n;

void kmp(){
	ll preSuArr[n]; preSuArr[0] = 0;
	ll prev = 0;
	FOR(i, 1, n){
		while(needle[prev] != 0 && needle[i] != needle[prev] && prev > 0) prev = preSuArr[prev-1];

		if(needle[i] == needle[prev] || needle[prev] == 0){
			prev ++;
			preSuArr[i] = prev;
		}
		else preSuArr[i] = 0;
	}

	ll res = 0;
	prev = 0;
	FOR(i, 0, s.length()){
		while(needle[prev] != 0 && hay[i] != needle[prev] && prev > 0)	prev = preSuArr[prev-1];
		if(hay[i] == needle[prev] || needle[prev] == 0) prev ++;
		if(prev >= n){
			res ++;
			prev = preSuArr[prev-1];
		}
	}
	cout << res << etr;
}

void gen(){
	ll la[26];
	FOR(i, 0, 26) la[i] = -1;
	FOR(i, 0, s.length()){
		hay[i] = (la[s[i]  - 'a'] == -1 ? 0 : i - la[s[i]  - 'a']);
		la[s[i] - 'a'] = i;
	}
	FOR(i, 0, 26) la[i] = -1;
	FOR(i, 0, n){
		needle[i] = (la[s2[i]  - 1] == -1 ? 0 : i - la[s2[i]  - 1]);
		la[s2[i] - 1] = i;
	}
}

int main(){
	cin >> s;
	cin >> n;
	FOR(i, 0, n) cin >> s2[i];
	gen();
	kmp();
	return 0;
}
