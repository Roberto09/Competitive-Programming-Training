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
#define INF 1E10

ll a, b, c, at, bt, ct, n;

ll arr[100050], aarr[100050], barr[100050], carr[100050];

ll tms[100050];

struct action{
	ll currState;
	ll  time;
	ll id;
	action(ll currState, ll time, ll id){
		this->currState = currState;
		this->time = time;
		this->id = id;
	}
};

class comp {
public:
    bool operator() (action &a, action &b) {
        if(a.time == b.time)
        	return a.currState < b.currState;
        return a.time > b.time;
    }
};

int main(){
	sync;
	cin >> a >> b >> c >> at >> bt >> ct;
	cin >> n;
	FOR(i, 0, n) cin >> arr[i];

	priority_queue<action, vector<action>, comp> acts;

	FOR(i, 0, n){
		//cout << "pushing i: " << i << etr;
		acts.push(action(0, arr[i], i));
	}

	ll mxTime = 0;
	ll ia = -1, ib = -1, ic = -1;
	ll currTime = 0;
	//cout << "size: " << acts.size() << etr;
	while(!acts.empty()){
		action curr = acts.top(); acts.pop();
		//cout << "curr: " << curr.id << " " << curr.currState << etr;
		currTime = curr.time;
		if(curr.currState == 0){
			ia ++; ia %= a;
			aarr[ia] = max(currTime + at, aarr[ia] + at);
			acts.push(action(1, aarr[ia], curr.id));
			tms[curr.id] += aarr[ia] - currTime;
		}
		else if(curr.currState == 1){
			ib ++; ib %= b;
			barr[ib] = max(currTime + bt, barr[ib] + bt);
			acts.push(action(2, barr[ib], curr.id));
			tms[curr.id] += barr[ib] - currTime;
		}
		else if(curr.currState == 2){
			ic ++; ic %= c;
			carr[ic] = max(currTime + ct, carr[ic] + ct);
			acts.push(action(3, carr[ic], curr.id));
			tms[curr.id] += carr[ic] - currTime;
		}
		else if(curr.currState == 3){
			mxTime = max(mxTime, tms[curr.id]);
		}
	}

	cout << mxTime << etr;
	return 0;
}
