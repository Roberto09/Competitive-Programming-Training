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
#define INF 1E10
struct node{
	ll sumUpToHere, valueAtHere;
	ll mn;
	vi neig;
	bool even;
};


void setup(vector<node> &nds, ll parent, ll curr, ll prevLev){
	if((prevLev + 1) % 2 == 0){
		nds[curr].even = true;
		nds[curr].valueAtHere = 0;
		nds[curr].sumUpToHere = INF;
	}
	else{
		nds[curr].even = false;
		nds[curr].valueAtHere = 0;
	}

	FOR(i,0,nds[curr].neig.size()){
		if(nds[curr].neig[i] == parent) continue;
		setup(nds, curr, nds[curr].neig[i], prevLev + 1);
	}
}

ll setupMin(vector<node> &nds, ll parent, ll curr, ll prevLev){
	ll minimum = INF;
	FOR(i,0,nds[curr].neig.size()){
		if(nds[curr].neig[i] == parent) continue;
		minimum = min(setupMin(nds, curr, nds[curr].neig[i], prevLev + 1), minimum);
	}
	nds[curr].mn = minimum;
	return min(minimum, nds[curr].sumUpToHere);
}


bool canBe = true;
void alg(vector<node> &nds, ll parent, ll curr, ll parentSum){
	if(nds[curr].even){
		//INF?
		if(nds[curr].mn == INF){
			nds[curr].valueAtHere = 0;
			return;
		}
		ll posVal = nds[curr].mn - parentSum;
		if(posVal < 0){
			canBe = false;
			return;
		}
		nds[curr].valueAtHere = posVal;
		FOR(i,0,nds[curr].neig.size()){
			if(nds[curr].neig[i] == parent) continue;
			alg(nds, curr, nds[curr].neig[i], parentSum + nds[curr].valueAtHere);
		}
	}
	else{
		nds[curr].valueAtHere = nds[curr].sumUpToHere - parentSum;
		FOR(i,0,nds[curr].neig.size()){
			if(nds[curr].neig[i] == parent) continue;
			alg(nds, curr, nds[curr].neig[i], nds[curr].sumUpToHere);
		}
	}
}


int main(){
	ll n;
	 cin >> n;
	 vector<node> nds(n);
	 ll w;
	 FOR(i, 1, n){
	 	cin >> w;
	 	w --;
	 	nds[i].neig.pb(w);
	 	nds[w].neig.pb(i);
	 }
	 ll x;
	 FOR(i, 0, n){
	 	cin >> x;
	 	if(x == -1) continue;
	 	else nds[i].sumUpToHere = x;
	 }

	 setup(nds, -1, 0, 0);
	 setupMin(nds, -1, 0, 0);

	 alg(nds, -1, 0, 0);
	 if(canBe){
	 	ll sum = 0;
	 	FOR(i, 0, n){
	 		sum += nds[i].valueAtHere;
	 	}
	 	cout << sum << etr;
	 }
	 else{
	 	cout << -1 << etr;
	 }

	return 0;
}