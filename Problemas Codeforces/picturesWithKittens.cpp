#include <iostream>
#include <algorithm>
using namespace std;

void readCool(int n, int arr[]){
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr, arr+n);
}
void readNotCool(int n){
	int x;
	for(int i = 0; i < n; i++) cin >> x;
}

int main(){
	int n, k, x;
	cin >> n >> k >> x;
	if(k == 1 && x < n){
		readNotCool(n);
		cout << -1 << "\n";
	}
	else{
		int arr[n];
		readCool(n, arr);
		unsigned long long sum = 0;
		for(int i = 0; i<x; i++) sum += arr[n-i-1];
		cout << sum << "\n";
	}
	return 0;
}