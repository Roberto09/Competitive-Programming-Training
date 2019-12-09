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
#define sz(x) (ll)(x).size()xs
#define endl '\n'
#define clockon ll t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }
#define oo 2000000000000000000LL
#define EPS 1e-6
#define MOD 1000000007
#define etr "\n"
#define INF 1E15

ll n, m;

vector<pair<char, ll>> a, a2;
vector<pair<char, ll>> b, b2;
bool check(ll i, ll j){
	if(i == 0 || j == a2.size()-1) return false;
	return (a2[i-1].second >= b2[0].second && a2[j+1].second >= b2[b2.size()-1].second && a2[i-1].first == b2[0].first && a2[j+1].first == b2[b2.size()-1].first);
}


ll kmp(vector<pair<char, ll>> a, vector<pair<char, ll>> b){
	a.erase(a.begin());
	a.erase(a.end());
	ll preSuArr[a.size()]; preSuArr[0] = 0;
	ll prev = 0;
	FOR(i, 1, a.size()){
		while((a[i].first != a[prev].first || a[i].second != a[prev].second) && prev > 0) prev = preSuArr[prev-1];

		if(a[i] == a[prev]){
			prev ++;
			preSuArr[i] = prev;
		}
		else preSuArr[i] = 0;
	}

	ll res = 0;
	prev = 0;
	FOR(i, 0, b.size()){
		while((b[i] != a[prev] || b[i].second != a[prev].second) && prev > 0)	prev = preSuArr[prev-1];
		if(b[i] == a[prev]) prev ++;
		if(prev >= a.size()){
			if(check(i-prev+1, i)) res ++;
			prev = preSuArr[prev-1];
		}
	}
	return res;
}

void normalize(vector<pair<char, ll>> &x, vector<pair<char, ll>> &x2){
	pair<char, ll> prev = x[0];

	FOR(i, 1, x.size()){
		pair<char, ll> &curr = x[i];
		if(curr.first == prev.first){
			prev.second += curr.second;
		}
		else{
			x2.pb(prev);
			prev = curr;
		}
	}
	x2.pb(prev);
}

int main(){
	cin >> n >> m;
	string s;
	FOR(i, 0, n){
		cin >> s;
		ll nmbr = stoi(s.substr(0, s.length() - 2));
		ll chrtr = s[s.length() -1];
		a.pb(mp(chrtr, nmbr));
	}

	FOR(i, 0, m){
		cin >> s;
		ll nmbr = stoi(s.substr(0, s.length() - 2));
		ll chrtr = s[s.length() -1];
		b.pb(mp(chrtr, nmbr));
	}



	normalize(a, a2);
	normalize(b, b2);

	if(b2.size() == 1){
		ll rs = 0;
		FOR(i, 0, a2.size()){
			if(a2[i].first == b2[0].first && a2[i].second >= b2[0].second)
				rs += a2[i].second - b2[0].second + 1;
		}
		cout << rs << etr;
		return 0;
	}
	else if(b2.size() == 2){
		ll rs = 0;
		FOR(i, 0, a2.size()){
			if(check(i+1, i)) rs++;
		}
		cout << rs << etr;
		return 0;
	}

	cout << kmp(b2, a2) << etr;

	return 0;
}