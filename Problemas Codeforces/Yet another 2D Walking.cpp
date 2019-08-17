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
#define INF 1E17

struct level{
	ii minLeft;
	ii minRight;
	vi dp;
	level(){
		minLeft = mp(INF, -INF);
		minRight = mp(-INF, INF);
	}
};

ll getDistance(ii &a, ii &b){
	return abs(a.first - b.first) + abs(a.second - b.second);
}

map<ll, level> levels;
ll getBest(map<ll, level> :: iterator lev, ii dp[], bool startLeft, ll dpIdx){
	//get next level
	map<ll, level> :: iterator nextLev = lev;
	nextLev ++;
	//hemos llegado al final
	if(nextLev == levels.end()){
		if(startLeft)
			return getDistance(lev->second.minLeft, lev->second.minRight);
		else
			return getDistance(lev->second.minRight, lev->second.minLeft);
	}

	if(startLeft){
		//checamos dp
		if(dp[dpIdx].first != -INF) return dp[dpIdx].first;
		ll startLeftEndRightGoLeftNext = getDistance(lev->second.minLeft, lev->second.minRight) + getDistance(lev->second.minRight, nextLev->second.minLeft) + getBest(nextLev, dp, true, dpIdx+1);
		ll startLeftEndRightGoRightNext = getDistance(lev->second.minLeft, lev->second.minRight) + getDistance(lev->second.minRight, nextLev->second.minRight) + getBest(nextLev, dp, false, dpIdx+1);
		return dp[dpIdx].first = min(startLeftEndRightGoLeftNext, startLeftEndRightGoRightNext);
	}
	else{
		if(dp[dpIdx].second != -INF) return dp[dpIdx].second;
		ll startRightEndLeftGoLeftNext = getDistance(lev->second.minRight, lev->second.minLeft) + getDistance(lev->second.minLeft, nextLev->second.minLeft) + getBest(nextLev, dp, true, dpIdx+1);
		ll startRightEndLeftGoRightNext = getDistance(lev->second.minRight, lev->second.minLeft) + getDistance(lev->second.minLeft, nextLev->second.minRight) + getBest(nextLev, dp, false, dpIdx+1);
		return dp[dpIdx].second = min(startRightEndLeftGoLeftNext, startRightEndLeftGoRightNext);
	}
}

int main(){
	sync;
	ll n;
	cin >> n;
	ll a, b, lv;
	FOR(i, 0, n){
		cin >> a >> b;
		//a is level
		lv = max(a, b);
		if(!levels.count(lv)) levels[lv] = level();
		level &lev = levels[lv];

		if(a <= lev.minLeft.first && b >= lev.minLeft.second) lev.minLeft = mp(a, b);
		if(b <= lev.minRight.second && a >= lev.minRight.first) lev.minRight = mp(a, b);
	}

	level levFirst;
	levFirst.minLeft = levFirst.minRight = mp(0, 0);
	levels[0] = levFirst;

	ii dp[levels.size()];
	FOR(i, 0, levels.size()) dp[i] = mp(-INF, -INF);

	cout << getBest(levels.begin(), dp, true, 0);
	return 0;
}