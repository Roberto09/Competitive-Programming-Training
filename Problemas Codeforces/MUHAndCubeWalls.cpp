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
#define INF 1E9 + 1;

ll elephant[200005];
ll bears[200005];
ll epattern[200005];

void generatePattern(ll e){
	ll c = 0;
	epattern[0] = 0;

	FOR(i, 1, e){
		if(elephant[i] == elephant[c]){
			c++;
			epattern[i] = c;
		}
		else{
			while(c != 0){
				c--;
				c = epattern[c];
				if(elephant[i] == elephant[c]) break;
			}
			if(elephant[i] == elephant[c]){
				c++;
				epattern[i] = c;
			}
			else
				epattern[i] = 0;
		}
	}
}

int main(){
	sync;
	ll e, b;
	cin >> b >> e;

	ll last, last2;
	cin >> last;

	FOR(i, 0, b-1){
		cin >> last2;
		bears[i] = last2 - last;
		last = last2;
	}

	cin >> last;
	FOR(i, 0, e-1){
		cin >> last2;
		elephant[i] = last2 - last;
		last = last2;
	}

	e--; 
	b--;
	if(e > b){
		cout << 0 << etr;
		return 0;
	}
	else if(e == 0){
		cout << b+1 << etr;
		return 0;
	}

	generatePattern(e);

	ll result = 0;
	ll ei = 0;
	FOR(bi, 0, b){
		if(elephant[ei] == bears[bi]){
			ei ++;
		}
		else{
			while(ei != 0){
				ei --;
				ei = epattern[ei];
				if(elephant[ei] == bears[bi]) break;
			}
			if(elephant[ei] == bears[bi]) ei++;
		}

		//comprobar resultado
		if(ei == e){
			result ++;
			ei --;
			ei = epattern[ei];
		}
	}

	cout << result << etr;
	return 0;
}