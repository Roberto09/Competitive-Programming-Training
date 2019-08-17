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
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << '\n';
}

ll checkStr(string &c, string &pre, string &suf){
	bool bpre = true;
	bool bsuf = true;
	FOR(i, 0, c.length()){
		if(pre[i] != c[i]) bpre = false;
	}
	FOR(i, 0, c.length()){
		if(suf[suf.length() - i - 1] != c[c.length() - i - 1]) bsuf = false;
	}
	if(bpre && bsuf) return 3;
	if(bpre) return 1;
	return 2;
}

int main(){
	ll n; cin >> n;
	vector<string> strs(2*n - 2);
	FOR(i, 0, strs.size()){
		cin >> strs[i];
	}

	vector<string> presuf;
	string secondBig = "";
	bool special = false;
	FOR(i, 0, strs.size()){
		if(strs[i].length() == n-1){
			presuf.pb(strs[i]);
		}
		else if(strs[i].length() == n-2){
			if(strs[i] == secondBig) special = true;
			secondBig = strs[i];
		}
	}

	string pre, suf;

	if(special){
		bool ceroPre = true;
		FOR(i, 0, secondBig.length()){
			if(presuf[0][i] != secondBig[i]) ceroPre = false;
		}
		if(ceroPre){
			pre = presuf[0];
			suf = presuf[1];
		}
		else{
			pre = presuf[1];
			suf = presuf[0];
		}
	}
	else{
		bool ceroPre = true;
		FOR(i, 0, n-2){
			if (presuf[0][i] != presuf[1][i+1]) ceroPre = false;
		}
		if(ceroPre){
			pre = presuf[1];
			suf = presuf[0];
		}
		else{
			pre = presuf[0];
			suf = presuf[1];
		}
	}

	vector<char> res(2*n-2);
	ll left = 0, right = 0;
	FOR(i, 0, res.size()){
		ll check = checkStr(strs[i], pre, suf);
		if(check == 1){
			res[i] = 'P';
			left ++;
		}
		else if(check == 2){
			res[i] = 'S';
			right ++;
		}
		else{
			res[i] = 'x';
		}
	}

	ll eitherpre = (res.size() / 2) - left;
	ll eithersuf = (res.size() / 2) - right;
	bool skiped = false;

	unordered_set<string> repeated;
	FOR(i, 0, res.size()){
		if(res[i] == 'x' && eitherpre != 0){
			if(repeated.count(strs[i])) continue;
			res[i] = 'P';
			eitherpre --;
			repeated.insert(strs[i]);
		}
	}
	FOR(i, 0, res.size()){
		if(res[i] == 'x' && eithersuf != 0){
			res[i] = 'S';
			eithersuf --;
		}
	}

	FOR(i,0 , res.size()){
		cout << res[i];
	}
	cout << etr;
	return 0;
}