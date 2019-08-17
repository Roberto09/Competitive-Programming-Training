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
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
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
#define INF 1E9 + 1;

struct segmentInfo{
	ii maxComingFromLeft;
	ii maxComingFromRight;
};

ll getBiggestDiference(segmentInfo &lNode, segmentInfo &rNode){
	return min(lNode.maxComingFromLeft.second, rNode.maxComingFromRight.second) - max(lNode.maxComingFromLeft.first, rNode.maxComingFromRight.first);
}

int main(){
	sync;
	ll n;
	cin >> n;
	ii segments[n];

	FOR(i, 0, n){
		cin >> segments[i].first >> segments[i].second;
	}

	segmentInfo dp[n];
	//precalculate
	ll maxLeftComingFromLeft = 0, minRightComingFromLeft = INF;
	ll maxLeftComingFromRight = 0, minRightComingFromRight = INF;
	FOR(i, 0 , n){
		//Coming form left
		maxLeftComingFromLeft = max(maxLeftComingFromLeft, segments[i].first);
		minRightComingFromLeft = min(minRightComingFromLeft, segments[i].second);
		dp[i].maxComingFromLeft.first = maxLeftComingFromLeft;
		dp[i].maxComingFromLeft.second = minRightComingFromLeft;
		//Coming form Right
		maxLeftComingFromRight = max(maxLeftComingFromRight, segments[n-i-1].first);
		minRightComingFromRight = min(minRightComingFromRight, segments[n-i-1].second);
		dp[n-i-1].maxComingFromRight.first = maxLeftComingFromRight;
		dp[n-i-1].maxComingFromRight.second = minRightComingFromRight;
	}

	ll best = 0;
	
	//first
	if(dp[1].maxComingFromRight.second - dp[1].maxComingFromRight.first > best)
		best = dp[1].maxComingFromRight.second - dp[1].maxComingFromRight.first;
	
	//mid
	FOR(i, 1, n-1){
		if(getBiggestDiference(dp[i-1], dp[i+1]) > best)
			best = getBiggestDiference(dp[i-1], dp[i+1]);
	}

	//last
	if(dp[n-2].maxComingFromLeft.second - dp[n-2].maxComingFromLeft.first > best)
		best = dp[n-2].maxComingFromLeft.second - dp[n-2].maxComingFromLeft.first;

	cout << best << etr;

	return 0;
}