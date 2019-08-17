#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef long long ll;

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
	vector<pair<double, ll> > probs;
	double alphaProb;
};


node heap[31];

string names[16];

double probWin[16][16];

void clear(){
	FOR(i, 0, 31){
		heap[i].probs.clear();
	}
}

//getResult(i, 0, 15, 0);
bool getResult(ll shouldWin, ll start, ll end, ll pos){
	node &act = heap[pos];
	//last sublevel -> base case
	if(start+1 == end){
		ll left = start;
		ll right = end;
		if(left == shouldWin || right == shouldWin){
			if(left == shouldWin){
				act.alphaProb = probWin[left][right];
			}
			else{
				act.alphaProb = probWin[right][left];
			}
			return true;
		}
		else{
			act.probs.pb(mp(probWin[left][right], left));
			act.probs.pb(mp(probWin[right][left], right));
			return false;
		}
	}

	ll mid = (start + end) / 2;
	bool lB = getResult(shouldWin, start, mid, 2*pos + 1);
	bool rB = getResult(shouldWin, mid+1, end, 2*pos + 2);
	node &left = heap[2*pos+1];
	node &right = heap[2*pos+2];
	//ninguno es, merge total
	if(!lB && !rB){
		double currProb;
		FOR(i, 0, left.probs.size()){
			FOR(j, 0, right.probs.size()){
				currProb = left.probs[i].first * right.probs[j].first * probWin[left.probs[i].second][right.probs[j].second];
				act.probs.pb(mp(currProb, left.probs[i].second));
			}	
		}

		FOR(i, 0, left.probs.size()){
			FOR(j, 0, right.probs.size()){
				currProb = left.probs[i].first * right.probs[j].first * probWin[right.probs[j].second][left.probs[i].second];
				act.probs.pb(mp(currProb, right.probs[j].second));
			}
		}

		return false;
	}
	else if(lB){
		double sum = 0;
		FOR(i, 0, right.probs.size()){
			sum += left.alphaProb * right.probs[i].first * probWin[shouldWin][right.probs[i].second];
		}
		act.alphaProb = sum;
		return true;
	}
	else{
		double sum = 0;
		FOR(i, 0, left.probs.size()){
			sum += right.alphaProb * left.probs[i].first * probWin[shouldWin][left.probs[i].second];
		}
		act.alphaProb = sum;
		return true;
	}
}

int main(){
	sync;
	FOR(i, 0, 16) cin >> names[i];

	FOR(i, 0, 16){
		FOR(j, 0, 16){
			cin >> probWin[i][j];
			probWin[i][j] /= 100.0;	
		}
	}
	FOR(i, 0, 16){
		clear();
		getResult(i, 0, 15, 0);
		//cout << heap[3].alphaProb << etr;
		FOR(j, 0, 10){
			if(j >= names[i].length()) cout << " ";
			else cout << names[i][j];
		}
		cout << " p=" << fixed << setprecision(2) << heap[0].alphaProb*100.0 << "\%" << etr;
	}

	return 0;
}