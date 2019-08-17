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
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); ////cout.tie(NULL)
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
#define INF 1E16
#define NV 1E17

ll t, n, m;
double circlePoints[42];
double dp[42][42][42];

double getAngle(double p1, double p2){
	double difference;
	difference = p2 - p1;
	return (difference) * 2.0 * PI;
}

double subTriangleArea(ll pi1, ll pi2, ll pi3){
	double p1 = circlePoints[pi1], p2 = circlePoints[pi2], p3 = circlePoints[pi3];
	double base1 = sqrt(2.0 - 2.0 * (cos(getAngle(p1, p2))));
	double base2 = sqrt(2.0 - 2.0 * (cos(getAngle(p2, p3))));
	double teta1 = asin((sin(getAngle(p1, p2)) / base1));
	double teta2 = asin((sin(getAngle(p2, p3)) / base2));
	double fteta = (teta1 + teta2) - (PI/2.0);
	return (base1 * (base2 * cos(fteta)))/2.0;
}


//										  never changes
double getBest(ll currPoint, ll verCount, ll left, ll right){
	//normalizamos el currPoint
	if(currPoint == n) currPoint = 0;
	//casos base
	//llegamos al final
	if(currPoint == left){
		if(verCount == m) return 0;
		return -1;
	}
	if(verCount == m) return 0;

	if(dp[left][right][verCount] != -2) return dp[left][right][verCount];

	//casos default
	double use, notUse;
	//agarrar el actual
	use = getBest(currPoint+1, verCount +1, left, currPoint);
	if(left != right && use != -1) use += subTriangleArea(left, right, currPoint);
	//hacerle skip
	notUse = getBest(currPoint+1, verCount, left, right);

	return dp[left][right][verCount] = max(use, notUse);
}

double singleTestCase(){
	double maxArea = 0;
	FOR(i, 0, n){
		maxArea = max(getBest(i+1, 1, i, i), maxArea);
	}
	return maxArea;
}

void clear(){
	FOR(i, 0, n){
		FOR(j, 0, n){
			FOR(k, 0, m){
				dp[i][j][k] = (double) -2;
			}
		}
	}
}

int main(){
	sync;
	do{
		cin >> n >> m;
		clear();
		if(n != 0 && m != 0){
			FOR(i, 0, n) cin >> circlePoints[i];
			//FOR(i, 0, n) cout << circlePoints[i] << " ";
			//cout << etr;
			cout << fixed << setprecision(6) << singleTestCase() << etr;
		}
	}
	while(n != 0 && m != 0);
	return 0;
}