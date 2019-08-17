#include <iostream>
using namespace std;

int main(){
	long long t, a, b, k;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> a >> b >> k;
		if(k%2 == 0){
			cout << a*((k/2)) - b*(k/2) << "\n";
		}
		else{
			cout << a*((k/2) + 1) - b*(k/2) << "\n";
		}
	}

	return 0;
}