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
#define INF 1E9

ll f, c;
struct food{
	ll rem;
	ll cost;
	ll pos;
};
struct costumer{
	ll type;
	ll ammount;
};

int main(){
	sync;
	cin >> f >> c;
	food fds[f];
	ll getPos[f];
	costumer cln[c];

	FOR(i, 0, f){
		cin >> fds[i].rem;
		fds[i].pos = i;
		//ordered.insert()
	}

	FOR(i, 0, f){
		cin >> fds[i].cost;
	}

	FOR(i, 0, c){
		cin >> cln[i].type >> cln[i].ammount;
		cln[i].type --;
	}
	sort(fds, fds + f, [](const auto &a, const auto &b){
	if(a.cost == b.cost){
		return a.pos < b.pos;
	}
	return a.cost < b.cost;
	});

//cout << "---" << etr;
	FOR(i, 0, f){
		getPos[fds[i].pos] = i;
		//cout << fds[i].pos << " " << fds[i].cost << etr;
	}
//cout << "---" << etr;

	ll actualCheapest = 0;
	ll res = 0;
	FOR(i, 0, c){
		res = 0;
		costumer &act = cln[i];
		ll type = act.type;
		ll ammount = act.ammount;
		if(ammount <= fds[getPos[type]].rem){
			res += fds[getPos[type]].cost * ammount;
			fds[getPos[type]].rem -= ammount;
		}
		else{
			ll pos = fds[getPos[type]].rem;
			res += fds[getPos[type]].cost * pos;
			fds[getPos[type]].rem = 0;
			//buscas y comienzas a agotar
			ll remmaining = ammount - pos;
			//cout << "rem : " << remmaining << etr;
			ll str = actualCheapest;
			FOR(j, str, f){
				if(fds[j].rem == 0){
					actualCheapest = j;
					continue;
				}
				if(remmaining <= fds[j].rem){
					//cout << "a" << etr;
					res += fds[j].cost * remmaining;
					fds[j].rem -= remmaining;
					remmaining = 0;
					break;
				}
				else{
					//cout << "b" << etr;
					res += fds[j].cost * fds[j].rem;
					remmaining -= fds[j].rem;
					fds[j].rem = 0;
					//cout << "rem : " << remmaining << "  --- " << res << etr;
				}
			}
			if(remmaining != 0) res = 0;
		}
		cout << res << etr;
	}

	return 0;
}