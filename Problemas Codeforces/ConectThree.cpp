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
#define INF 1E9

int main(){
	vii prs(3);
	FOR(i, 0, 3){
		cin >> prs[i].first >> prs[i].second;
	}

	sort(prs.begin(), prs.end());

	ll  sum = 3;
	
	sum += abs(prs[1].first - prs[0].first);
	sum += abs((prs[1].second - prs[0].second))-1;

	//find y axis intercept
	if(prs[2].second <= (prs[0].second > prs[1].second ? prs[0].second : prs[1].second) && prs[2].second >= (prs[0].second > prs[1].second ? prs[1].second : prs[0].second)){
		sum += abs(prs[2].first - prs[1].first) - 1;
	}
	else if(prs[2].second < prs[0].second && prs[0].second < prs[1].second){
		sum += abs(prs[2].first - prs[1].first);
		sum += abs(prs[0].second - prs[2].second) - 1;
	}
	else if(prs[2].second > prs[0].second && prs[0].second > prs[1].second){
		sum += abs(prs[2].first - prs[1].first);
		sum += abs(prs[2].second - prs[0].second) - 1;
	}
	else{
		sum += abs(prs[2].first - prs[1].first);
		sum += abs((prs[2].second - prs[1].second))-1;
	}

	cout << sum << etr;

	//x A-B
	//y A-B
	FOR(i, 0, prs[1].first - prs[0].first + 1){
		cout << prs[0].first + i << " " << prs[0].second << etr;
	}
	if(prs[0].second < prs[1].second){
		FOR(i, 1, abs(prs[1].second - prs[0].second)+1){
			cout << prs[1].first << " " << prs[0].second + i << etr;
		}
	}
	else{
		FOR(i, 1, abs(prs[1].second - prs[0].second)+1){
			cout << prs[1].first << " " << prs[0].second - i << etr;
		}
	}




	if(prs[2].second <= (prs[0].second > prs[1].second ? prs[0].second : prs[1].second) && prs[2].second >= (prs[0].second > prs[1].second ? prs[1].second : prs[0].second)){
		FOR(i, 0, prs[2].first - prs[1].first){
			cout << prs[2].first - i << " " << prs[2].second << etr;
		}
	}
	else if(prs[2].second < prs[0].second && prs[0].second < prs[1].second){
		//desplazamiento en x
		FOR(i, 1, prs[2].first - prs[1].first + 1){
			cout << prs[1].first + i << " " << prs[0].second << etr;
		}
		FOR(i, 1, prs[0].second - prs[2].second + 1){
			cout << prs[2].first << " " << prs[0].second - i << etr;
		}
	}
	else if(prs[2].second > prs[0].second && prs[0].second > prs[1].second){
		//desplazamiento en x
		FOR(i, 1, prs[2].first - prs[1].first + 1){
			cout << prs[1].first + i << " " << prs[0].second << etr;
		}
		FOR(i, 1, prs[2].second - prs[0].second + 1){
			cout << prs[2].first << " " << prs[0].second + i << etr;
		}
	}
	else{
		//x B-C
		//y B-B
		FOR(i, 1, prs[2].first - prs[1].first + 1){
			cout << prs[1].first + i << " " << prs[1].second << etr;
		}

		if(prs[1].second < prs[2].second){
			FOR(i, 1, abs(prs[2].second - prs[1].second)+1){
				cout << prs[2].first << " " << prs[1].second + i << etr;
			}
		}
		else{
			FOR(i, 1, abs(prs[2].second - prs[1].second)+1){
				cout << prs[2].first << " " << prs[1].second - i << etr;
			}
		}
	}
	return 0;
}