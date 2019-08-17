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


struct sqr{
	vii coords;
};


int main(){
	sync;
	sqr s1, s2;
	s1.coords.resize(4);
	s2.coords.resize(4);
	FOR(i, 0, 4){
		cin >> s1.coords[i].first;
		cin >> s1.coords[i].second;
	}
	FOR(i, 0, 4){
		cin >> s2.coords[i].first;
		cin >> s2.coords[i].second;
	}

	sort(s1.coords.begin(), s1.coords.end(), [] (const auto& lhs, const auto& rhs) {
    if(lhs.first == rhs.first){
    	return lhs.second < rhs.second;
    }
    return lhs.first < rhs.first;
});

	ii auxpair;
	auxpair = s1.coords[2];
	s1.coords[2] = s1.coords[3];
	s1.coords[3] = auxpair;
	//checar is estan dentro los puntos
	FOR(i, 0, 4){
		ii refPoint = s2.coords[i];
		if(refPoint.first >= s1.coords[0].first && refPoint.first <= s1.coords[3].first){
			if(refPoint.second <= s1.coords[2].second && refPoint.second >= s1.coords[0].second){
				cout << "YES" << etr;
				return 0;
			}
		}
	}

	//checar lineas tan
	FOR(i, 0, 4){
		ii c1 = s2.coords[i%4], c2 = s2.coords[(i + 1) % 4];
		ll mNum = c1.second - c2.second;
		ll mDen = c1.first - c2.first;
		ll m = mNum / mDen;
		ll b = c1.second - ((m * c1.first));

		ii cx1 = s1.coords[0], cx2=s1.coords[1], cx3=s1.coords[2], cx4=s1.coords[3];
		//arriba
		ll y = cx2.second;
		ll x = (y - b) / m;
		if(x >= cx2.first && x <= cx3.first){
			if((x >= c1.first && x <= c2.first) || (x >= c2.first && x <= c1.first)){
				if((y >= c1.second && y <= c2.second) || (y >= c2.second && y <= c1.second)){
					cout << "YES" << etr;
					return 0;
				}
			}
		}
		//abajo
		y = cx1.second;
		x = (y - b) / m;
		if(x >= cx1.first && x <= cx4.first){
			if((x >= c1.first && x <= c2.first) || (x >= c2.first && x <= c1.first)){
				if((y >= c1.second && y <= c2.second) || (y >= c2.second && y <= c1.second)){
					cout << "YES" << etr;
					return 0;
				}
			}
		}
	}

	//last resource

	sort(s2.coords.begin(), s2.coords.end(), [] (const auto& lhs, const auto& rhs) {
    if(lhs.first == rhs.first){
    	return lhs.second < rhs.second;
    }
    return lhs.first < rhs.first;
});

	bool flag = true;
	FOR(i, 0, 4){
		ii p = s1.coords[i];
		if(!((p.first >= s2.coords[0].first && p.first <= s2.coords[3].first) && (p.second >= s2.coords[1].second && p.second <= s2.coords[2].second))){
			flag = false;
		}
	}
	if(flag){
		ii auxPair = s2.coords[2];
		s2.coords[2] = s2.coords[3];
		s2.coords[3] = auxPair;
		//contar el numero de intersecciones
		//sacamos un punto aleatorio
		ll count = 0;
		ii cx1 = s1.coords[0];
			FOR(i, 0, 4){
			ii c1 = s2.coords[i%4], c2 = s2.coords[(i + 1) % 4];
			ll mNum = c1.second - c2.second;
			ll mDen = c1.first - c2.first;
			ll m = mNum / mDen;
			ll b = c1.second - ((m * c1.first));

			ll y = cx1.second;
			ll x = (y - b) / m;
			if(x > cx1.first) continue;
			if((x >= c1.first && x <= c2.first) || (x >= c2.first && x <= c1.first)){
				count ++;
			}
		}
		if(count % 2 != 0){
			cout << "YES" << etr;
			return 0;
		}
	}

	cout << "NO" << etr;

	return 0;
}