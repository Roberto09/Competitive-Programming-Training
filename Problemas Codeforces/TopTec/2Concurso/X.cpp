#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
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
#define INF 10E10

double getDistance(pair<double, double> a, pair<double, double> b){
	return sqrt((b.second - a.second)*(b.second-a.second) + (b.first-a.first)*(b.first-a.first));
}

double getAngle(double a, double b, double c){
	return acos((a*a + b*b - c*c) / (2 * a * b));
}
double getAngle2(double a, double b, double c){
	return acos((c*c + b*b - a*a) / (2 * c * b));
}

double getArea(pair<double, double> d, pair<double, double> e, pair<double, double> f){
	double de, ef, df;
	de = getDistance(d, e);
	ef = getDistance(e, f);
	df = getDistance(d, f);
	double area = (df * ef * sin(getAngle(ef, df, de))) / 2;
	return area;
}

pair<pair<double, double>, pair<double, double>> getPoints(double area, pair<double, double> a, pair<double, double> b, pair<double, double> c){
	double base = getDistance(a, b);
	double yD = area / base;
	double bacAng = getAngle2(getDistance(b, c), getDistance(a, b), getDistance(a, c));
	double xD = yD / tan(bacAng);
	
	double hip = sqrt(yD*yD + xD*xD);
	//cout << hip << etr;
	double m;
	double xDisplacement, yDisplacement;

	if(c.first != a.first){
		m = ((c.second - a.second) / (c.first - a.first));
		xDisplacement = sqrt((hip * hip) / (m*m+1));
		if(c.first < a.first) xDisplacement *= -1;
		yDisplacement = m * xDisplacement;
	}
	else{
		xDisplacement = 0;
		yDisplacement = hip;
		if(c.second < a.second) yDisplacement*= -1;
	}

	pair<double, double> h = mp(a.first + xDisplacement, a.second + yDisplacement);
	pair<double, double> g = mp(b.first + xDisplacement, b.second + yDisplacement);
	return mp(h, g);
}

int main(){
	//sync;
	pair<double, double> a, b, c, d, e, f;
	while(true){
		cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >> d.first >> d.second >> e.first >> e.second >> f.first >> f.second;
		if(a.first == 0 && a.second == 0 && b.first == 0 && b.second == 0 && c.first == 0 && c.second == 0 && d.first == 0 && d.second == 0 && e.first == 0 && e.second == 0 && f.first == 0 && f.second == 0) break;
		double defArea = getArea(d, e, f);
		//cout << defArea << etr;
		pair<pair<double, double>, pair<double, double>> res = getPoints(defArea, a, b, c);
		cout << setprecision(3) << fixed <<res.second.first << " " << res.second.second << " " << res.first.first << " " << res.first.second << etr;
	}
	return 0;
}