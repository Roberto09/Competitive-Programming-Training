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
#define clockoff debug("Elapsed Time: %.3f\n", (long double)(clock() - z) / CLOCKS_PER_SEC); }
#define oo 2000000000000000000LL
#define EPS 1e-6
#define MOD 1000000007
#define etr "\n"
#define INF 1E18

ll a, b;
vi bs;
string s;

ll move(ll cnt){
	ll res = 0;
	ll prevB = 0;
	string ss = s;
	
	//move cnt b to front
	ll l = 0, r = s.size() - 1;
	FOR(i, 0, cnt){
		while(l < r){
			if(ss[l] != 'W') l ++;
			else if(ss[r] != 'B') r--;
			else{
				swap(ss[l], ss[r]);
				res += a;
				l++; r--; break;
			}
		}
	}

	ll wcnt = 0;
	FOR(i, l, ss.size()){
		if(ss[i] == 'W') wcnt++;
		else res += wcnt*(a-b);
	}
	return res;
}

void solve(){
	cin >> s;
	//try all
	ll ans = INF;
	FOR(i, 0, s.length()+1){
		ans = min(ans, move(i));
	}
	cout << ans << etr;

}

int main(){
	while(cin >> a >> b){
		solve();
	}
	return 0;
}