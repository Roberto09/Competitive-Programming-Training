#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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
ll w, m;

ll fastPow(ll a, ll b){
    ll ret = 1;
    while(b > 0){
        if(b&1) ret = (ret*a);
        a = (a*a);
        b >>= 1;
    }
    return ret;
}

ll findStart(ll dif){
	ll x = (ull)w;
	ll currStart = 0;
	ll currS = 1;
	ll curr = 1;
	while(currS < dif){
		curr *= x;
		currS += curr;
		currStart ++;
	}
	return currStart;
}

bool getRes(ll left, ll right, ll prevPow){
//	cout << left << " " << right << etr;
	if(left == right) return true;
	ll dif = llabs(left - right);
	//cout << "dif: " << dif << etr;
	ll start = findStart(dif);
//	cout << "dif: " << dif << etr;
//	cout << "start: " << start << etr;

	if(start >= prevPow) return false;
	if(left < right){
		return getRes(left + fastPow(w, start), right, start);
	}
	else{
		return getRes(left, right+ fastPow(w, start), start);
	}
}

int main(){
	cin >> w >> m;
	if(getRes(m, 0, INF))
		cout << "YES" << etr;
	else
		cout << "NO" << etr;
	return 0;
}