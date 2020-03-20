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

struct node{
	string a;
	ll feq;
};

ll MaxW, n;
ll max_feq;


ll solve(vector<node>& aux){
	ll sum = 0;
	ll act_max = 0;
	ll act_width = 0;
	bool flag = true;
	FOR(i,0,n){
		ll height = ceil(8 + (40 * (aux[i].feq - 4) / (double)(max_feq - 4)));
		ll width = ceil(9.0000 / 16.000 * aux[i].a.size() * height);
		//cout << height << "      " << width << endl;
		//Cabe
		if(act_width + width <= MaxW){
			//flag = false;
			act_width += width + 10;
			act_max = max(act_max, height);
		}else{
			//cout << "Cambie con : " << aux[i].a << endl;
			sum += act_max;
			act_max = height;
			act_width = width + 10;
			//flag = true;
		}
	}
	sum += act_max;


	return sum;

}

int main(){
	sync;
	cin >> MaxW >> n;
	ll cont = 1;

	while(MaxW && n){
		vector<node> aux(n);
		max_feq = 0;
		FOR(i,0,n){
			cin >> aux[i].a >> aux[i].feq;
			max_feq = max(max_feq, aux[i].feq);
		}

		//cout << "CLOUD 1:"solve(aux) << endl;
		cout << "CLOUD " << cont++ << ": " << solve(aux) << endl;
		cin >> MaxW >> n;
	}

	return 0;
}