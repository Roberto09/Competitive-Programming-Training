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
	ll  cnt;
	ll bestResCanUse;
	ll bestResCantUse;
	node(){
		cnt = 0;
		bestResCanUse = -INF;
		bestResCantUse = -INF;
	}
};
ll n;
map<ll, node> mp;

ll getBest(auto it, ll usedPrev){
	if(it == mp.end()) return 0;
	auto itNext = it;
	itNext ++;
	if(it->first == usedPrev+1){
		ll notUse;
		if(it->second.bestResCantUse != -INF) notUse = it->second.bestResCantUse;
		else notUse = getBest(itNext, usedPrev);
		return it->second.bestResCantUse = notUse;
	}
	else{
		ll use, notUse;
		if(it->second.bestResCanUse != -INF) use = it->second.bestResCanUse;
		else it->second.bestResCanUse = use = it->second.cnt * it->first + getBest(itNext, it->first);

		if(it->second.bestResCantUse != -INF) notUse = it->second.bestResCantUse;
		else it->second.bestResCantUse = notUse = getBest(itNext, usedPrev);
		return max(use, notUse);
	}
}

int main(){
	cin >> n;
	ll x;
	FOR(i,0 , n){
		cin >> x;
		if(!mp.count(x)){
			mp[x] = node();
		}
		mp[x].cnt ++;
	}
	cout << getBest(mp.begin(), -100);
	return 0;
}