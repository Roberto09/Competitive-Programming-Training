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
#define sz(x) (ll)(x).length()
#define endl '\n'
#define clockon ll t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }
#define oo 2000000000000000000LL
#define EPS 1e-6
#define MOD 1000000007
#define etr "\n"
#define INF 1E18

ll n, m , k;

pair<ii, ii> arr[52];

// dp[count][curridx][nth val usado(1-100)]
ll dp[52][52][102];
bool checkedDp[52][52][102];

// first -> siguiente idx    second -> nextEx
ii trace[52][52][102];

ll individualCase(ll currIdx, ll count, ll currEx){
	if(checkedDp[count][currIdx][currEx - arr[currIdx].first.first]) return dp[count][currIdx][currEx - arr[currIdx].first.first];
	if(n == count){
		return currEx;
	}
	ll lastPos = m - (n-count) + 1;
	ll posSum = currEx + k;
	ll posMult = currEx * k;
	ll maxPos = -INF;
	ll nextIdx;
	bool sum = false;
	FOR(i, currIdx+1, lastPos+1){
		if(arr[i].second.first == arr[currIdx].second.first) continue;
		pair<ii, ii> next = arr[i];
		if(posSum >= next.first.first && posSum <= next.first.second){
			ll pos = individualCase(i, count + 1, posSum);
			if(pos > maxPos){
				maxPos = pos;
				nextIdx = i;
				sum = true;
			}
		}
		if(posMult >= next.first.first && posMult <= next.first.second){
			ll pos = individualCase(i, count + 1, posMult);
			if(pos > maxPos){
				maxPos = pos;
				nextIdx = i;
				sum = false;
			}		
		}
	}	
	checkedDp[count][currIdx][currEx - arr[currIdx].first.first] = true;
	if(maxPos == -INF)
		return dp[count][currIdx][currEx - arr[currIdx].first.first] = -INF;

	trace[count][currIdx][currEx - arr[currIdx].first.first].first = nextIdx;
	if(sum) trace[count][currIdx][currEx - arr[currIdx].first.first].second = posSum;
	else trace[count][currIdx][currEx - arr[currIdx].first.first].second = posMult;

	return dp[count][currIdx][currEx - arr[currIdx].first.first] = maxPos + currEx;
}

ll startRec(ll &startIdx, ll &value){
	ll maxRes = -INF;
	FOR(i, 1, m+1){
		pair<ii, ii> curr = arr[i];
		FOR(j, curr.first.first, curr.first.second+1){
			ll pos = individualCase(i, 1, j);
			if(pos == -INF) continue;
			if(pos > maxRes){
				maxRes = pos;
				startIdx = i;
				value = j;
			}
		}
	}
	return maxRes;
}

void printRes(ll pos, ll val){
	ll currIdx = pos, value = val, auxcurrIdx;
	FOR(i, 1, n+1){
		cout << arr[currIdx].second.second << " " << value << etr;
		auxcurrIdx = trace[i][currIdx][value-arr[currIdx].first.first].first;
		value = trace[i][currIdx][value-arr[currIdx].first.first].second;
		currIdx = auxcurrIdx;
	}
}

int main(){
	sync;
	cin >> n >> m >> k;
	arr[0].first.first = arr[0].first.second = arr[0].second.first = -1;
	FOR(i, 1, m+1){
		cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second.first;
		arr[i].second.second = i;
	}
	sort(arr, arr+m+1, [](const auto &l, const auto &r){
		return l.second.first < r.second.first;
	});

	FOR(i, 0, m+1){
		FOR(j, 0, m+1){
			FOR(k, 0, 102){
				checkedDp[i][j][k] = false;
			}
		}
	}

	ll pos, val;
	if(startRec(pos, val) == -INF) cout << "NO" << etr;
	else{
		cout << "YES" << etr;
		printRes(pos, val);
	}
	return 0;
}
