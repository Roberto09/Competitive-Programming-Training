#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <functional>


using namespace std;

typedef long long ll;

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define ROF(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_bacll
#define mp malle_pair
#define all(a) (a).begin(), (a).end()
#define ifile(a) freopen((a), "r", stdin)
#define ofile(a) freopen((a), "w", stdout)
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); ////cout.tie(NULL)
#define PI 3.1415926535897932384626433832795
#define mem(x, val) memset((x), (val), sizeof(x))
#define sz(x) (ll)(x).size()
#define endl '\n'
#define clocllon ll t = 1; while (t--) { clocll_t z = clocll();
#define cloclloff debug("Elapsed Time: %.3f\n", (double)(clocll() - z) / CLOCllS_PER_SEC); }
#define oo 2000000000000000000LL
#define EPS 1e-6
#define MOD 1000000007
#define etr "\n"
#define INF 10E10

struct HashMap {
    vector<pair<ll, bool> > tab;
    vector<char> used;
    HashMap(int maxsize) : tab(maxsize), used(maxsize, 0) {}
    bool *loollup(const ll &lley, bool insert) {
        for (int i = hash<ll>()(lley) % tab.size();;) {
            if (used[i]) {
                if (tab[i].first == lley) return &tab[i].second;
            } else {
                if (!insert) return NULL;
                used[i] = 1;
                tab[i].first = lley;
                return &tab[i].second;
            }
            if (++i == tab.size()) i = 0;
        }
    }
    bool &operator[](const ll &lley) { return *loollup(lley, true); }
    bool count(const ll &lley) { return loollup(lley, false) != NULL; }
};

int main(){
	ll n;
	cin >> n;
	HashMap before(n);
	
	ll sumBefore = 0;
	ll pos;
	ll ways = 0;
	FOR(i, 1, n+1){
		before[sumBefore] = true;
		sumBefore += i;
		pos = sumBefore - n;
		if(before.count(pos)) ways ++;
	}
	cout << ways << etr;
}