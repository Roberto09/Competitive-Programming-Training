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
ll len, disturb, env;

ll arrA[100005];
ll arrB[100005];

ll dp[205][100005];

ll recursion(ll disturb, ll actualIndex){
	if(dp[disturb][actualIndex] != -1) return dp[disturb][actualIndex];
	//casos base
	if(actualIndex == len)
		return 0;

	if(arrA[actualIndex] == -1) return dp[disturb][actualIndex] = recursion(disturb, actualIndex+1);
	if(disturb == 0) return dp[disturb][actualIndex] = recursion(disturb, arrB[actualIndex]) + arrA[actualIndex];

	//casos regulares
	//comprar
	ll comprar = recursion(disturb, arrB[actualIndex]) + arrA[actualIndex];
	//no comprar
	ll noComprar = recursion(disturb-1, actualIndex + 1);

	return dp[disturb][actualIndex] = min(comprar, noComprar);
}

struct lex_compare {
    bool operator() (const ii& a, const ii& b) const {
        if(a.first == b.first){
        	return a.second > b.second;
        }
        return a.first > b.first;
    }
};

struct event{
	ll idx, pos;
	bool isStart;
};

int main(){
	sync;
	cin >> len >> disturb >> env;
	len ++;
	ii envs[env];
	event events[env*2];

	FOR(i, 0, disturb+2){
		FOR(j, 0, len+2){
			dp[i][j] = -1;
		}
	}

	ll s, e, d, c;
	FOR(i, 0, env){
		cin >> s >> e >> d >> c;
		envs[i] = mp(c, d+1);
		events[i].idx = i;
		events[i].pos = s;
		events[i].isStart = true;
		events[env+i].idx = i;
		events[env+i].pos = e+1;
		events[env+i].isStart = false;
	}

	sort(events, events+env*2, [](const auto &e1, const auto &e2){
		return e1.pos < e2.pos;
	});

	map<ii, ll, lex_compare> pq;

	ll j = 0;
	FOR(i, 1, len){
		FOR(e, j, env*2){
			event &act = events[e];
			if(act.pos == i){
				if(act.isStart){
					if(pq.count(envs[act.idx]))
						pq[envs[act.idx]] ++;
					else
						pq[envs[act.idx]] = 1;
				}
				else{
					if(pq[envs[act.idx]] == 1) pq.erase(envs[act.idx]);
					else pq[envs[act.idx]] --;
				}
			}
			else{
				j = e;
				break;
			}
		}
		if(pq.size() > 0){
			arrA[i] = pq.begin()->first.first;
			arrB[i] = pq.begin()->first.second;
		}
		else{
			arrA[i] = -1;
			arrB[i] = -1;
		}
	}

	cout << recursion(disturb, 1);

	return 0;
}