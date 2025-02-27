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
#define INF 1E9 + 1;

ll elephant[200005];
ll bears[200005];
ll epattern[200005];


void kmp(string &a, string &b){
	ll preSuArr[a.length()]; preSuArr[0] = 0;
	ll prev = 0;
	FOR(i, 1, a.length()){
		while(a[i] != a[prev] && prev > 0) prev = preSuArr[prev-1];

		if(a[i] == a[prev]){
			prev ++;
			preSuArr[i] = prev;
		}
		else preSuArr[i] = 0;
	}

	ll res = 0;
	prev = 0;
	FOR(i, 0, b.length()){
		while(b[i] != a[prev] && prev > 0)	prev = preSuArr[prev-1];
		if(b[i] == a[prev]) prev ++;
		if(prev >= a.length()){
			res ++;
			prev = preSuArr[prev-1];
		}
	}
	cout << res << etr;
}

void generatePattern(ll e){
	epattern[0] = 0;
	ll prev = 0;
	FOR(i, 1, e){
		while(elephant[i] != elephant[prev] && prev > 0) prev = epattern[prev-1];

		if(elephant[i] == elephant[prev]){
			prev ++;
			epattern[i] = prev;
		}
		else epattern[i] = 0;
	}
}

int main(){
	sync;
	ll e, b;
	cin >> b >> e;

	ll last, last2;
	cin >> last;

	FOR(i, 0, b-1){
		cin >> last2;
		bears[i] = last2 - last;
		last = last2;
	}

	cin >> last;
	FOR(i, 0, e-1){
		cin >> last2;
		elephant[i] = last2 - last;
		last = last2;
	}

	e--; 
	b--;
	if(e > b){
		cout << 0 << etr;
		return 0;
	}
	else if(e == 0){
		cout << b+1 << etr;
		return 0;
	}

	generatePattern(e);

	ll res = 0;
	ll prev = 0;
	FOR(i, 0, b){
		while(bears[i] != elephant[prev] && prev > 0)	prev = epattern[prev-1];
		if(bears[i] == elephant[prev]) prev ++;
		if(prev >= e){
			res ++;
			prev = epattern[prev-1];
		}
	}
	cout << res << etr;
	return 0;
}