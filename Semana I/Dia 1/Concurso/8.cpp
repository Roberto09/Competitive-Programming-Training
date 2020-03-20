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
#define INF 1E18

ll w, n, d;

bool arr[8650];
double dist[8650];
vi nmbrs;
double mx;

bool getRes(double mxx, ll strt){
	ll curr = strt;
	double currsum = 0.0;
	FOR(i, 0, w){
		while(currsum + dist[curr] <= mxx){
			currsum += dist[curr];
			curr ++;
			curr %= nmbrs.size();
			if(curr == strt) return true;
		}
		curr ++;
		curr %= nmbrs.size();
		if(curr == strt) return true;
		currsum = 0.0;
	}
	//cout << "strt-> " << strt << "  curr-> " << curr << etr;
	return false;
}

double getSubRes(double mid){
	FOR(i, 0, nmbrs.size()){
		if(getRes(mid, i)) return true;
	}
	return false;
}

double check(){
	double l = 0.0, r = mx + 50;
	double best = INF;
	while(abs(l-r) >= 0.005){
		//cout << idx << etr;
		double mid = (l + r) / 2.0;
		bool opt = getSubRes(mid);
		if(opt){
			best = mid;
			r = mid;
		}else{
			l = mid;
		}
	}
	return best;
}

void solve(){
	nmbrs.clear();
	mem(arr, false);
	FOR(i , 0, d){
		ll x;
		ll ant;
		cin >> x;
		ant = x;
		while(x<=n){ 
			arr[x] = true;
			x += ant;
		}
	}
	mx = 0.0;
	double statang = 2.0*PI/double(n);
	FOR(i, 1, n+1)
		if(arr[i]) nmbrs.pb(i);
	FOR(i, 0, nmbrs.size()){
		if(i == nmbrs.size()-1){
			dist[i] = 2000.0 * sin(double(n + nmbrs[0] - nmbrs[i]) * statang/2.0);
			continue;
		}
		dist[i] = 2000.0 * sin(double(nmbrs[i+1] - nmbrs[i]) * statang/2.0);
		mx += dist[i];
	}
	double res = INF;
	/*
	FOR(i, 0, nmbrs.size()){
		res = min(res, check(i));
	}
	*/
	res = check();
	cout << setprecision(1) << fixed << res + 2000.0<< etr;
}
 
int main(){
	sync;
	while(true){
		cin >> w;
		if(!w) break;
		cin >> n >> d;
		solve();
	}
	return 0;
}