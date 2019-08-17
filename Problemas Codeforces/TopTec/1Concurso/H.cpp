#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

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

ii dp[1002][1002];
ll n, classDuration, c;
ll topics[1002];

ll formula(ll t){
	if(t == 0) return 0;
	else if(t <= 10) return -c;
	else return (t-10) * (t-10);
}

void clear(){
	FOR(i, 0, n){
		FOR(j, 0, n){
			dp[i][j] = mp(-INF, -INF);
		}
	}
}

ii getBest(ll currClass, ll currTopic){	
	if(currTopic == n) return mp(0, 0);

	if(dp[currClass][currTopic].first != -INF) return dp[currClass][currTopic];

	//debemos probar todas las opciones
	ll currTime = topics[currTopic];
	ll minClassesNeeded, minDi;
	ii currRes;

	//sin meterle ninguno extra
	currRes = getBest(currClass+1, currTopic + 1);
	minClassesNeeded = 1 + currRes.first;
	minDi = currRes.second + formula(classDuration - currTime);

	//metiendole extras
	FOR(tpc, currTopic + 1, n){
		//si podemos juntar esta clase
		if(currTime + topics[tpc] <= classDuration){
			currTime += topics[tpc];
			//caculamso el siguiente resultado
			currRes = getBest(currClass+1, tpc+1);
			//agregamos al siguiente resultado
			currRes.first += 1; // agregamos la actual
			currRes.second += formula(classDuration - currTime);
			if(currRes.first < minClassesNeeded || (currRes.first == minClassesNeeded && currRes.second < minDi)){
				minClassesNeeded = currRes.first;
				minDi = currRes.second;
			}
		}
		else break;
	}

	return dp[currClass][currTopic] = mp(minClassesNeeded, minDi);
}

/*


Case 1:
Minimum number of lectures: 2
Total dissatisfaction index: 0


*/

int main(){
	sync;
	ll cse = 1;
	while(true){
		cin >> n;
		if(n == 0) break;
		if( != 1) cout << etr;
		cin >> classDuration >> c;
		clear();
		FOR(i, 0, n) cin >> topics[i];
		ii res = getBest(0, 0);
		cout << "Case " << cse << ":" << etr;
		cout << "Minimum number of lectures: " << res.first << etr;
		cout << "Total dissatisfaction index: " << res.second << etr;
		cse ++;
	}
	return 0;
}