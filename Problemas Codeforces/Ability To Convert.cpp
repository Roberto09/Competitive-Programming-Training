#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
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
#define etr "\n"
#define INF 18446744073709551614

ll n, nsz;
string k;

ll fastPow(ll a, ll b){
    ll ret = 1;
    while(b > 0){
        if(b&1) ret = (ret*a);
        a = (a*a);
        b >>= 1;
    }
    return ret;
}

ll expo(ll nmbr, ll pwr){
	return nmbr*(fastPow(n, pwr));
}

ll dpc(ll idx, ll pwr){
	if(idx >= k.length()) return 0;
	ll biggest = idx;
	string nmbr = "";
	FOR(i, idx, min(idx + nsz, ll(k.length()))){
		nmbr += k[i];
		string op = nmbr; reverse(op.begin(), op.end());
		ll lop = stoll(op);
		if(lop >= n) break;
		if(k[i] == '0') continue;
		else biggest = i;
	}
	nmbr = "";
	FOR(i, idx, biggest+1) nmbr += k[i];
	string op = nmbr; reverse(op.begin(), op.end());
	ll lop = stoll(op);
	return expo(lop, pwr) + dpc(biggest+1, pwr + 1);
}

ll getLen(ll x){
	ll rs = 0;
	while(x != 0){
		rs ++;
		x /= 10;
	}
	return rs;
}


int main(){
	cin >> n >> k;
	nsz = getLen(n);
	reverse(k.begin(), k.end());
	cout << dpc(0, 0) << etr;
	return 0;
}