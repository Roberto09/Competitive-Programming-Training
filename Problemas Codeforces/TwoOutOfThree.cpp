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
#define INF 1E10

ll n;
ll prs;
stack<ll> s;
stack<ii> q;

//dp [recursion level] [index of top of stack]
ii dp[502][1002];

ll individualCase(ll prev1, ll prev2, ll pos){
	ii election;
	ii n1, n2, n3;
	ll minRes = INF;
	ll op1, op2, op3; op1 = op2 = op3 = INF;

	if(dp[pos][q.top().second].first != -1)	
		return dp[pos][q.top().second].first + max(prev1, prev2);
	if(q.size() == 2){
		n1 = q.top(); q.pop();
		n2 = q.top(); q.pop();
		q.push(n2); q.push(n1);
		dp[pos][q.top().second].first = max(n1.first, n2.first);
		return dp[pos][q.top().second].first + max(prev1, prev2);;
	}
	else if(q.size() == 1){
		dp[pos][q.top().second].first = q.top().first;
		return dp[pos][q.top().second].first + max(prev1, prev2);
	}

	n1 = q.top(); q.pop();
	n2 = q.top(); q.pop();
	n3 = q.top(); q.pop();

	q.push(n3);
	op1 = individualCase(n1.first, n2.first, pos+1);
	q.pop(); q.push(n2);
	op2 = individualCase(n1.first, n3.first, pos+1);
	q.pop(); q.push(n1);
	op3 = individualCase(n2.first, n3.first, pos+1);

	minRes = min(op1, minRes);
	minRes = min(op2, minRes);
	minRes = min(op3, minRes);

	if(minRes == op1) election = n3;
	else if(minRes == op2) election = n2;
	else election = n1;

	q.pop(); q.push(n3); q.push(n2); q.push(n1);
	dp[pos][q.top().second].second = election.second;
	dp[pos][q.top().second].first = minRes;
	return minRes + max(prev1, prev2);
}

void reconstructPath(){
	ii n1, n2, n3;
	ll lev = 1;
	ll dismiss = dp[0][1].second;
	while(!q.empty()){
		if(q.size() == 1){
			cout << q.top().second << etr;
			break;
		}
		else if(q.size() == 2){
			cout << q.top().second << " ";
			q.pop();
			cout << q.top().second << etr;
			break;
		}
		n1 = q.top(); q.pop();
		n2 = q.top(); q.pop();
		n3 = q.top(); q.pop();
		if(dismiss == n1.second){
			cout << n2.second << " " << n3.second << etr;
			q.push(n1);
			dismiss = dp[lev][n1.second].second;
		}
		else if(dismiss == n2.second){
			cout << n1.second << " " << n3.second << etr;
			q.push(n2);
			dismiss = dp[lev][n2.second].second;
		}
		else{
			cout << n1.second << " " << n2.second << etr;
			q.push(n3);
			dismiss = dp[lev][n3.second].second;
		}
		lev ++;
	}
}

void setup(){
	FOR(i, 0, n/2 + 1){
		FOR(j, 0, n+1){
			dp[i][j].first = -1;
			dp[i][j].second = -1;
		}
	}
}

int main(){
	ll x;
	cin >> n;
	prs = n/2;
	FOR(i, 0, n){
		cin >> x;
		s.push(x);
	}

	FOR(i, 0, n){
		q.push(mp(s.top(), n-i));
		s.pop();
	}

	setup();
	//setDp();
	cout << individualCase(0, 0, 0) << etr;
	reconstructPath();
	return 0;
}