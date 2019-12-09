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
#define INF 1E15

struct dps{
	ll ai, bi, ci, n;
	dps(ll ni, ll a, ll b, ll c){
		ai = a; bi = b; n = ni; ci = c;
	}
	dps(){
		ai = bi = ci = n = -1;
	}
};

string a, b, v;
// char1 - char 2 - previn substr
dps dp[105][105][105];
dps track[105][105][105];
ll preSuArr[105];

void kmp(string &a){
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

dps lcs(ll ai, ll bi, ll comp){
	if(ai >= a.length() || bi >= b.length()) return dps(0, -1, -1, -1);
	if(dp[ai][bi][comp].n != -1) return dp[ai][bi][comp];
	if(a[ai] == b[bi]){
		//kmp comp goes here
		ll prev = comp;
		while(b[bi] != v[prev] && prev > 0)	prev = preSuArr[prev-1];
		if(b[bi] == v[prev]) prev ++;
		if(prev >= v.length()){
			//aqui hay pedos, encontramos substring
			return lcs(ai+1, bi+1, comp);
		}
		else{
			//agregar
			dps o1 = lcs(ai+1, bi+1, prev); o1.n ++;
			//no agregar
			dps o2 = lcs(ai+1, bi+1, comp);
			if(o1.n > o2.n){
				track[ai][bi][comp] = dps(o1.n-1, o1.ai, o1.bi, o1.ci);
				o1.ai = ai; o1.bi = bi; o1.ci = comp;
				dp[ai][bi][comp] = o1;
				return o1;
			}
			else{
				dp[ai][bi][comp] = o2;
				return o2;
			}
		}
	}
	else{
		dps o1 = lcs(ai + 1, bi, comp);
		dps o2 = lcs(ai, bi + 1, comp);
		if(o1.n > o2.n){
			dp[ai][bi][comp] = o1;
			return o1;
		}
		else{
			dp[ai][bi][comp] = o2;
			return o2;
		}
	}
	return dps(0, -1, -1, -1); // pa k no truene
}

void path(dps curr){
	string res = "";
	while(curr.n != 0){
		res += a[curr.ai];
		curr = track[curr.ai][curr.bi][curr.ci];
	}
	if(res == "") cout << 0 << etr;
	else
		cout << res << etr;
}

int main(){
	cin >> a >> b >> v;
	kmp(v);
	dps x = lcs(0, 0, 0);
	path(x);
	return 0;
}
