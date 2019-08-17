#include <iostream>
using namespace std;

int main(){
	int s; 
	cin >> s;
	bool arr[s];
	int n;
	for(int i = 0; i < s; i++){
		cin >> n;
		arr[i] = n;
	}


	int k = 0;
	for(int i = 1; i < s-1; i++){
		if(arr[i] == false && (arr[i-1] && arr[i+1])){
			arr[i+1] = 0;
			k++;
		}
	}

	cout << k << "\n";

	return 0;
}