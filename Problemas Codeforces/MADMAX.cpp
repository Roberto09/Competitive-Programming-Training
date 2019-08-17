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

struct Node{
	vector<pair<char, ll>> neig;
};

char res[105][105];
bool dp[27][105][105];
bool dpIsCalculated[27][105][105];
bool currentlyWins[105][105];
ll lastPosCalc[105][105]; // last pos calculated in a

vector<Node> graph;
ll n, m;

int ps(char x){return (x - 'a') + 1;}

bool calculate(ll a, ll b, char prev){
	if(dpIsCalculated[ps(prev)][a][b])
		return dp[ps(prev)][a][b];

	bool can = currentlyWins[a][b];
	char prevChar = 'z';
	cout << a+1 << " " << b+1 << etr;
	FOR(i, lastPosCalc[a][b], graph[a].neig.size()){
		//escoges uno en a
		ll nextA = graph[a].neig[i].second;
		char valueNextA = graph[a].neig[i].first;
		if(valueNextA < prev){
			lastPosCalc[a][b] = i;
			break;
		}
		bool singleFightRes = true;
		//de acuerdo al escogido en a, escogemos uno en b
		FOR(j, 0, graph[b].neig.size()){
			ll nextB = graph[b].neig[j].second;
			char valueNextB =  graph[b].neig[j].first;
			if(valueNextB < valueNextA) break;
			singleFightRes = false;
			can |= calculate(nextA, nextB, valueNextB);
		}
		can |= singleFightRes;

		dp[ps(valueNextA)][a][b] |= can;
		dpIsCalculated[ps(valueNextA)][a][b] = true;

		FOR(i, ps(valueNextA)+1, ps(prevChar)+1){
			dp[i][a][b] = dp[ps(prevChar)][a][b];
			dpIsCalculated[i][a][b] = true;
		}
		prevChar = valueNextA;
	}
	if (can) cout << "aqui se volvio true por primera vez" << etr;
	return currentlyWins[a][b] = can;
}

void getRes(){
	if(calculate(4, 4, (char)('a'-1))) res[4][4] = 'A';
	else res[4][4] = 'B';
}

int main(){
	//sync;
	cin >> n >> m;
	graph.resize(n);
	ll a, b;
	char c;
	FOR(i, 0, m){
		cin >> a >> b >> c;
		a--;
		b --;
		graph[a].neig.pb(mp(c,b));
	}

	FOR(i, 0, n) sort(graph[i].neig.begin(), graph[i].neig.end(), [](const pair<char, ll> &k, const pair<char, ll> w){
		return k.first > w.first;
	});
	//mem(dp, (char)('a' - 1))
	mem(dp, false);
	mem(dpIsCalculated, false);
	mem(lastPosCalc, 0);
	mem(currentlyWins, false);
	getRes();

	FOR(i, 0, n){
		FOR(j, 0, n) cout << res[i][j] << " ";
		cout << etr;
	}
	return 0;
}