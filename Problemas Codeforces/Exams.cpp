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

ll d[100005];
ll e[100005];
ll days, exams;

bool checkPossible(ll last){
	vi lastPositions;
	ll curr;
	ROF(i, last, 0){
		curr = d[i];
		if(curr == 0) continue;
		if(e[curr] < 0) continue;
		e[curr] *= -1;
		lastPositions.pb(i);
	}

	FOR(i, 0, lastPositions.size()) e[d[lastPositions[i]]] *= -1;
	reverse(lastPositions.begin(), lastPositions.end());

	if(lastPositions.size() < exams) return false;

	ll prev = 0;
	ll prevPosition = 0;
	FOR(i, 0, lastPositions.size()){
		if(prev + (lastPositions[i] - prevPosition) < e[d[lastPositions[i]]]) return false;
		prev = prev + (lastPositions[i] - prevPosition) - e[d[lastPositions[i]]];
		prevPosition = lastPositions[i] + 1;
	}
	return true;
}

int main(){
	cin >> days >> exams;
	FOR(i, 0, days) cin >> d[i];
	FOR(i, 1, exams+1) cin >> e[i];
	
	ll l = 0, r = days-1, m;
	ll min = -2;
	while(l <= r){
		m = l + (r-l) / 2;
		if(checkPossible(m)){
			min = m;
			r = m-1;
		}
		else{
			l = m+1;
		}
	}
	cout << min + 1 << etr;
	return 0;
}