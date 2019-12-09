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
#define INF 1E9
 
struct circ{
	ll x, y, r;
	circ(){}
	circ(ll x, ll y, ll r){
		this->x = x;
		this->y = y;
		this->r = r;
	}
};
 
ll k = 1003;
ll n;
circ arr[1005];
vi graph[1005];
bool prnt[1005];


double dp[1005][2][2];
bool dpb[1005][2][2];
 
bool isContained(circ &a, circ &b){
	double dist = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	if(dist >= (double)a.r + b.r) return false;
	return true;
}
 
double calcArea(circ &c){
	double a = (double)PI * (double)c.r * (double)c.r;
	return a;
}
 
double getBest(ll currC, bool contA, bool contB){
	ll dpa = (contA ? 0 : 1);
	ll dpbb = (contB ? 0 : 1);
	if(dpb[currC][dpa][dpbb]) return dp[currC][dpa][dpbb];
	double o1, o2;
	o1 = calcArea(arr[currC]) * (contA ? 1 : -1);
	o2 = calcArea(arr[currC]) * (contB ? 1 : -1);
 
	for(ll neig : graph[currC]){
		o1 += getBest(neig, !contA, contB);
	}

	for(ll neig : graph[currC]){
		o2 += getBest(neig, contA, !contB);
	}
	dpb[currC][dpa][dpbb] = true;
	return dp[currC][dpa][dpbb] = max(o1, o2);
}
 
void createG(){
	sort(arr, arr+n, [](circ &a, circ&b){
		return a.r > b.r;
	});
 
	ROF(i, n-1, 0){
		FOR(j, i+1, n){
			if(isContained(arr[i], arr[j]) && !prnt[j]){
				prnt[j] = true;
				graph[i].pb(j);
			}
		}
	}
}
 
double calc(ll i){
	return getBest(i, true, true);
}
 
int main(){
	sync;
	cin >> n;
	ll x, y, r;
	FOR(i, 0, n){
		cin >> x >> y >> r;
		arr[i] = circ(x, y, r);
	}
	vi a, b;
	createG();
	double res = 0;
	FOR(i, 0, n){
		if(!prnt[i]){
			res += calc(i);
		}
	}
	cout << setprecision(15) << res << etr;
	return 0;
}