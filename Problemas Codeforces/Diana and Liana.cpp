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
#define INF 10E10

ll fl, segSize, popu, seqSize;

ll flowers[500010];
unordered_map<ll, ll> shouldContain;
unordered_map<ll, ll> dummy;

ll checkPossible(){
	ll errorMargin = fl - popu * segSize;
	
	unordered_map<ll, ll> extras;
	//setup inicial -> meter primeros segSize + errorMargin
	FOR(i, 0, segSize + errorMargin){
		ll act = flowers[i];
		//revisamos si el actual se encuentra en nuestro dummy
		if(dummy.count(act)){
			//lo quitamos
			dummy[act] --;
			if(dummy[act] == 0) dummy.erase(act);
		}
		//revisamos si el actual es parte de nuestro original (ya lo quitamos previamente y por ende es un extra
		else if(shouldContain.count(act)){
			//lo agregamos a los extras
			if(!extras.count(act)) extras[act] = 0;
			extras[act] ++;
		}
	}
	//primer caso
	if(dummy.empty()) return 0;

	//resto de los casos
	FOR(p, 1, popu){
		ll idx = p * segSize;

		//quitar los anteriores segSize
		FOR(i, idx - segSize, idx){
			//revisamso si esta contenido en los extras
			ll act = flowers[i];
			if(extras.count(act)){
				extras[act] --;
				if(extras[act] == 0) extras.erase(act);
			}
			//si no revisamos si esta contenido en los originales
			else if(shouldContain.count(act)){
				if(!dummy.count(act)) dummy[act] = 0;
				dummy[act] ++;
			}
		}

		//meter los siguientes segsize despues del error margin
		FOR(i, 0, segSize){
			ll act = flowers[idx + i + errorMargin];
			//revisamos si el actual se encuentra en nuestro dummy
			if(dummy.count(act)){
				//lo quitamos
				dummy[act] --;
				if(dummy[act] == 0) dummy.erase(act);
			}
			//revisamos si el actual es parte de nuestro original (ya lo quitamos previamente y por ende es un extra) 
			else if(shouldContain.count(act)){
				//lo agregamos a los extras
				if(!extras.count(act)) extras[act] = 0;
				extras[act] ++;
			}
		}

		//finalmente revisamos si este es un indice valido
		if(dummy.empty()) return idx;
	}
	return -1;
}

void buildPath(ll start){
	ll errorMargin = fl - popu * segSize;
	vi res;
	FOR(i, 0, segSize + errorMargin){
		if(res.size() == errorMargin) break;
		ll act = flowers[i + start];
		if(shouldContain.count(act)){
			shouldContain[act] --;
			if(shouldContain[act] == 0) shouldContain.erase(act);
		}
		else res.pb(i + start);
	}
	cout << res.size() << etr;
	FOR(i, 0, res.size()) cout << res[i]+1 << " ";
}

int main(){
	sync;
	cin >> fl >> segSize >> popu >> seqSize;
	FOR(i, 0, fl) cin >> flowers[i];
	
	ll x;
	FOR(i, 0, seqSize){
		cin >> x;
		if(!shouldContain.count(x)) shouldContain[x] = 0;
		shouldContain[x] ++;

		if(!dummy.count(x)) dummy[x] = 0;
		dummy[x] ++;
	}


	ll start = checkPossible();
	if(start < 0){
		cout << -1 << etr;
		return 0;
	}

	buildPath(start);

	return 0;
}