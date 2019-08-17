#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

typedef long long ll;

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

struct fecha{
	ll day, month, year;
};

/*
7
11/20/2005 11/21
11/20/2005 11/17
11/20/2005 11/20
11/20/2005 11/13
11/20/2005 11/28
1/2/2005 12/30
12/31/2100 1/3
*/
std::string toString(ll value)
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

ll myStoi(string s){
	ll res = 0;
	FOR(i,0,s.length()){
		res*=10;
		res += s[i] - '0';
	}
	return res;
}

ll getDaysMonth(ll m, ll y){
	if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 31;
	else if(m == 2){
		if((y%4 == 0 && y%100 != 0) || y%400 == 0) return 29;
		return 28;
	}
	else{
		return 30;
	}
}

ll getDifference(fecha f1, fecha f2){
	//cout << f2.day << etr;
	ll diasTotales = 0;
	//if(f2.month != f1.month ) return INF;
	FOR(i, f1.day, getDaysMonth(f1.month, f1.year)){
		diasTotales ++;
		//cout << "d1: " << diasTotales << etr;
		if(diasTotales > 7) return INF;
		if(f1.day + diasTotales == f2.day && f1.month == f2.month) return diasTotales;
	}
	f1.month ++;
	if(f1.month == 13){
		f1.month = 1;
		f1.year ++;
	}
	FOR(i, 1, f2.day+1){
		diasTotales ++;
		//cout << "d2: " << i << etr;
		if(diasTotales > 7) return INF;
		if(i == f2.day && f1.month == f2.month && f1.year == f2.year) return diasTotales;
	}
	return INF;
}

ll calculateDifference(fecha &f1, fecha &f2){
	ll dif;
	if(f1.day == f2.day && f1.month == f2.month && f1.year == f2.year) return 0;
	if(f1.year == f2.year){
		if(f1.month == f2.month){
			if(f1.day > f2.day){
				dif = getDifference(f2, f1);
				return (dif == INF ? INF : -dif);
			}
		}
		else if(f1.month > f2.month){
			dif = getDifference(f2, f1);
			return (dif == INF ? INF : -dif);
		}
	}
	else if(f1.year > f2.year){
		dif = getDifference(f2, f1);
		return (dif == INF ? INF : -dif);
	}
	dif = getDifference(f1, f2);
	return (dif == INF ? INF : dif);
}

int main(){
	sync;
	ll n;
	cin >> n;
	string a, b, ax, bx;
	fecha f1, f2;
	FOR(i, 0, n){
		cin >> a >> b;
		ax = a;
		f1.month = myStoi(a.substr(0, a.find('/')));
		a = a.substr(a.find('/') + 1);
		f1.day = myStoi(a.substr(0, a.find('/')));
		a = a.substr(a.find('/') + 1);
		f1.year = myStoi(a.substr(0, a.find('/')));

		f2.month = myStoi(b.substr(0, b.find('/')));
		b = b.substr(b.find('/') + 1);
		f2.day =  myStoi(b.substr(0, b.find('/')));

		f2.year = f1.year;
		ll dif1 = calculateDifference(f1, f2);
		//cout << etr;
		f2.year = f1.year-1;
		ll dif2 = calculateDifference(f1, f2);
		//cout << etr;
		f2.year = f1.year + 1;
		ll dif3 = calculateDifference(f1, f2);
		//cout << etr;

		bx = toString(f2.month) + "/" + toString(f2.day) + "/";

		ll dif;
		cout << i+1 << " ";
		////cout << "differences: " << dif1 << " " << dif2 << " " << dif3 << etr;
		if(dif1 == INF && dif2 == INF && dif3 == INF)	cout << "OUT OF RANGE" << etr;
		else{
			if(dif1 != INF){
				dif = dif1;
				bx += toString(f1.year);
			}
			else if(dif2 != INF){
				dif = dif2;
				bx += toString(f1.year-1);
			}
			else{
				dif = dif3;
				bx += toString(f1.year+1);
			}
			if(dif == 0) cout << "SAME DAY" << etr;
			else if(dif > 0) cout << bx << " IS " << abs(dif) << (abs(dif) > 1 ? " DAYS " : " DAY ") << "AFTER" << etr;
			else cout << bx << " IS " << abs(dif) << (abs(dif) > 1 ? " DAYS " : " DAY ") << "PRIOR" << etr;
		}
	}
	return 0;
}