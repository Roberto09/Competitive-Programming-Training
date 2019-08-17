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
	ll baloons;
	ll weight;
	ll dif;
	node(){};
	node(ll b, ll w){
		baloons = b;
		weight = w;
		dif = w - b;
	}
};


class comp2{
public:
    bool operator() (const node &n1, const node &n2){
        return n1.baloons < n2.baloons;
    }
};

class comp{
public:
    bool operator() (const node &n1, const node &n2){
        return n1.dif > n2.dif;
    }
};

vector<node> game;

int main(){
	ll n;
	cin >> n;
	ll pt, pw;
	ll t, w;

	cin >> pt >> pw;
	pw ++;

	ll tieCarry = 0;

	priority_queue<node, vector<node>, comp> top;
	priority_queue<node, vector<node>, comp2> bot;

	FOR(i, 1, n){
		cin >> t >> w;
		w++;
		if(t == pt){
			tieCarry++;
		}
		if(t>= pt){
			top.push(node(t, w));
		}
		else{
			bot.push(node(t, w));
		}
	}

	ll best = top.size() + 1 - tieCarry;
	node bestTop;
	while(!top.empty()){
		bestTop = top.top(); top.pop();
		ll dif = bestTop.dif;
		pt -= dif;
		if(pt < 0) break;

		tieCarry = 0;

		node currBot;
		while(!bot.empty() && bot.top().baloons >= pt){
			currBot = bot.top(); bot.pop();
			if(currBot.baloons == pt)
				tieCarry ++;
			top.push(currBot);
		}
		ll pos = top.size() + 1 - tieCarry;
		best = min(best, (ll)pos);
	}

	cout << best << etr;

	return 0;
}