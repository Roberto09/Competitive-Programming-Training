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

ll n, k;

queue<ll> entries;
ll maxTimeline;

struct node{
	ll duration;
	ll timeStart, timeEnd;
	node(){}
	node(ll d, ll ts, ll te){
		duration = d;
		timeStart = ts;
		timeEnd = te;
	}
};

class Compare{
public:
    bool operator() (const pair<ll, node> &n1, const pair<ll, node> &n2)
    {
        return n1.second.timeEnd > n2.second.timeEnd;
    }
};

ll calculateIntersections(){
	ll res = 0;
	ll id = 0;

	//id, nodo
	unordered_map<ll, node> current;
	priority_queue<pair<ll, node>, vector<pair<ll, node>>, Compare> nexts;

	FOR(i, 0, k){
		if(entries.empty()) break;
		node nde(entries.front(), 0, entries.front());
		current[id] = nde;
		nexts.push(mp(id, nde));
		entries.pop();
		id ++;
	}


	ll currPercentage = 0;
	ll currTime = 0;
	ll currDone = 0;
	pair<ll, node> nextClose;
	unordered_set<ll> alreadyInteresting;
	while(!nexts.empty()){
		//cout << currPercentage << etr;
		nextClose = nexts.top(); nexts.pop();
		ll idclse = nextClose.first;
		
		//checamos si el anterior percentage afecto a alguno de los anteriores
		node curr;
		ll counter = 0;
		//cout << "lowerbound: " << currTime << "   upperbound: " << nextClose.second.timeEnd  << etr;
		//cout << "level intersections: ";
		for(auto it = current.begin(); it != current.end(); it++){
			counter ++;
			curr = it->second;
			//falta agregar condicion con currtime
			if(currPercentage > (currTime - curr.timeStart) && currPercentage <= curr.duration - (curr.timeEnd - nextClose.second.timeEnd) && !alreadyInteresting.count(it->first)){
				res ++;
				//cout << curr.duration << " ";
				if(currDone != 0) alreadyInteresting.insert(it->first);
			}
		}
		//cout << etr;

		//agregamos a los done
		currDone ++;
		//calculamos el percentage
		currPercentage = round(100.0 * ((double)currDone / n));
		//le agregamos al time actual
		currTime = nextClose.second.timeEnd;
		//quitamos el actual del grupo
		current.erase(idclse);
		//agregamos uno nuevo si es que hay
		if(!entries.empty()){
			node nde(entries.front(), currTime, currTime+entries.front()); entries.pop();
			current[id] = nde;
			nexts.push(mp(id, nde));
			id ++;
		}
	}

	return res;
}

int main(){
	sync;
	cin >> n >> k;
	ll x;
	FOR(i, 0, n){
		cin >> x;
		entries.push(x);
	}

	cout << calculateIntersections() << etr;
	return 0;
}