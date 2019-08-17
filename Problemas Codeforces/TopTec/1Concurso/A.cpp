#include <iostream>
#include <string>
using namespace std;

typedef int ll;

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define ROF(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define etr "\n"


ll myStoi(string s){
	ll res = 0;
	FOR(i,0,s.length()){
		res*=10;
		res += s[i] - '0';
	}
	return res;
}

ll getHour(string s){
	ll n;
	ll number = myStoi(s.substr(0, s.find(':')));
	if(myStoi(s.substr(s.find(':') + 1)) != 0) return -1;
	return number;
}

int main(){
	ll t;
	string s;
	cin >> t;
	FOR(i, 0, t){
		cin >> s;
		ll x = getHour(s);
		if(x == -1) cout << 0 << etr;
		else if(x <= 12) cout << x + 12 << etr;
		else cout << x - 12 << etr;
	}

	return 0;
}