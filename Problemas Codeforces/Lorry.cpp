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


priority_queue<ii> t1, t2;
ll n, v;

ll getO1(){
	if(t1.empty()) return -INF;
	if(t1.size() == 1) return t1.top().first;
	ii a = t1.top(); t1.pop();
	ii b = t1.top(); t1.pop();
	t1.push(a); t1.push(b);
	return a.first + b.first;
}

ll getO2(){
	if(t2.empty()) return -INF;
	return t2.top().first;
}

int main(){
	sync;
	cin >> n >> v;
	ll a, b;
	ll fRes = 0;
	ll te = 0;
	FOR(i, 0, n){
		cin >> a >> b;
		if(a == 1) t1.push(mp(b, i+1));
		else t2.push(mp(b, i+1));
		fRes +=b;
		te += a;
	}
	if(te <= v){
		cout << fRes << etr;
		while(!t1.empty()){
			cout << t1.top().second << " ";
			t1.pop();
		}
		while(!t2.empty()){
			cout << t2.top().second << " ";
			t2.pop();
		}
		return 0;
	}

	ll res = 0;
	vi subRes;
	if(v%2 && !t1.empty()){
		res += t1.top().first;
		subRes.pb(t1.top().second);
		t1.pop();
	}

	FOR(i, 0, v/2){
		ll o1 = getO1();
		ll o2 = getO2();
		if(o2 == -INF && o1 == -INF) break;
		if(o1 > o2){
			res += o1;
			subRes.pb(t1.top().second);
			t1.pop();
			if(!t1.empty()){
				subRes.pb(t1.top().second);
				t1.pop();	
			}
		}
		else{
			res += o2;
			subRes.pb(t2.top().second);
			t2.pop();
		}
	}

	cout << res << etr;
	for(ll i : subRes) cout << i << " ";

	return 0;
}