#include <iostream>
#include <vector>
#include <map>
#include <string>
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

struct xd{
	string ptyy;
	ll count;
};
map<string, xd> cand;

int main(){
	sync;
	ll n;
	cin >> n;
	string name, party;
	cin.ignore();
	FOR(i, 0, n){
		//cout << i << etr;
		getline(cin, name);
		getline(cin, party);
		if(party == "independent") party = name;
		cand[name].ptyy = party;
		cand[name].count = 0;
	}
	//cout << "end reading" << etr;

	ll x; 
	cin >> x;
	cin.ignore();
	FOR(i, 0, x){
		//cout << i << etr;
		getline(cin, name);
		if(cand.count(name))
			cand[name].count ++;
	}

	ll best = 0;
	string pty = "";
	bool tie = false;
	for(map<string, xd> :: iterator it = cand.begin(); it != cand.end(); it++){
		ll nmbr = it->second.count;
		if(nmbr > best){
			tie = false;
			pty = it->second.ptyy;
			best = nmbr;
		}
		else if(nmbr == best){
			tie = true;
		}
	}
	if(tie) cout << "tie" << etr;
	else if(cand[pty].ptyy == pty) cout << "independent" << etr;
	else cout << pty << etr;

return 0;
}