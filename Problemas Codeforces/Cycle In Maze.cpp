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
#define INF 1E10

ll p1[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
ll p2[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

char mtrx[1005][1005];

ii m1[1005][1005];
ii m2[1005][1005];

ll n, m, k, a, b;

priority_queue<string, vector<string>, greater<string>> pq;

void clear(){
	FOR(i, 0, n){
		FOR(j, 0, m){
			m1[i][j] = m2[i][j] = mp(-1, -1);
		}
	}
}

char getC1(ll r, ll c){
	if(r == -1 && c == 0) return 'D';
	if(r == 0 && c == -1) return 'L';
	if(r == 0 && c == 1) return 'R';
	return 'U';
}

char getC2(ll r, ll c){
	if(r == -1 && c == 0) return 'U';
	if(r == 0 && c == -1) return 'R';
	if(r == 0 && c == 1) return 'L';
	return 'D';
}

string getRes(ll r, ll c){
	cout << r << " " << c << etr;
	string r1 = " ";
	string r2 = " ";
	// m1
	ll cr = r, cc = c;
	while(cr != a && cc != b){
		ll mr, mc;
		mr = cr - m1[cr][cc].first; mc = cc - m1[cr][cc].second;
		r1 += getC1(mr, mc);
	}
	reverse(r1.begin(), r1.end());
	//m2
	cr = r, cc = c;
	while(cr != a && cc != b){
		ll mr, mc;
		mr = cr - m2[cr][cc].first; mc = cc - m1[cr][cc].second;
		r2 += getC2(mr, mc);
	}
	return r1 + r2;
}

string doAlg(ll kk){
	clear();
	queue<ii> pos1, pos2;
	pos1.push(mp(a, b));
	pos2.push(mp(a, b));
	ll levc1 = 1;
	ll levc2 = 1;
	ll level = 1;
	while(!pos1.empty() && !pos2.empty()){
		// move 2
		ll lc = 0;
		FOR(w, 0, levc2){
			FOR(i, 0, 4){
				ll r = pos2.front().first + p2[i][0], c = pos2.front().second + p2[i][1];
				if(r >= n || r < 0 || c >= m || c < 0 || mtrx[r][c] != '.' || m2[r][c].first != -1) continue;
				// mark visited
				pos2.push(mp(r, c));
				m2[r][c] = pos2.front();
				lc ++;
			}
			pos2.pop();
		}
		levc2 = lc; lc = 0;
		// move 1
		FOR(w, 0, levc1){
			FOR(i, 0, 4){
				ll r = pos1.front().first + p1[i][0], c = pos1.front().second + p1[i][1];
				if(r >= n || r < 0 || c >= m || c < 0 || mtrx[r][c] != '.' || m1[r][c].first != -1) continue;
				// mark visited
				pos1.push(mp(r, c));
				m1[r][c] = pos1.front();
				lc ++;
				if(level == kk/2) return getRes(r, c);				
			}
			pos1.pop();
		}
		levc1 = lc; lc = 0;
		level  ++;
	}
	return "Z";
}

int main(){
	sync;
	cin >> n >> m >> k;

	FOR(i, 0, n){
		FOR(j, 0,  m){
			cin >> mtrx[i][j];
			if(mtrx[i][j] == 'X'){
				a = i; b = j;
			}
		}
	}

	ll ck = k;
	ll op = 1;
	while(ck % 2 == 0 && ck > 0){
		string tent = doAlg(ck);
		if(tent != "Z"){
			string supTent = "";
			FOR(i, 0, op) supTent += tent;
			pq.push(supTent);
		}
		ck /= 2;
		op *= 2;
	}
	cout << pq.size() << etr;
	if(pq.empty()) cout << "IMPOSSIBLE" << etr;
	else cout << pq.top() << etr;
	return 0;
}