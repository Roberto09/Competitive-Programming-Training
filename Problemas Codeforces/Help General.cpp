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
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); ////cout.tie(NULL)
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
#define INF 1E18
 
ll m;
ll h1, x1, k1, h2, x2, k2, a1, a2;
 
ll curr1 = h1;
ll p1 = -1;
ll cnt1 = 0;
ll curr2 = h2;
ll p2 = -1;
ll cnt2 = 0;
 
ll getRes(){
	ll a = p1, b = p2;
	//cout << a <<" " << b << etr;
	while(a != b){
		if(a < b) a+=cnt1;
		else b+=cnt2;
	}
	return a;
}
 
 
int main(){
	sync;
	cin >> m >> h1 >> a1 >> x1 >> k1 >> h2 >> a2 >> x2 >> k2;
 
	curr1 = h1; curr2 = h2;
	do{
		//cout << "Xd1" << etr;
		cnt1 ++;
		if(curr1 == a1){
			p1 = cnt1;
		}
		curr1 = ((curr1 * x1)%m + k1)%m;
	}while(curr1 != h1 && cnt1 <= m);
 
	if(p1 == -1){
		//cout << -1 << etr;
		return 0;
	}
 
 	//cout << "h2" << etr;
	do{
		cnt2 ++;
		if(curr2 == a2){
			p2 = cnt2;
		}
		curr2 = ((curr2 * x2)%m + k2)%m;
		//cout << curr2 << etr;
	}while(curr2 != h2 && cnt2 <= m);
 
	if(p2 == -1){
		//cout << -1 << etr;
		return 0;
	}
	cout << getRes()-1 << etr;
 
	return 0;
}