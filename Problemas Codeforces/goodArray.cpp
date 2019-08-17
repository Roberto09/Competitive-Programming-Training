#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
	int n;
	cin >> n;

	unordered_map<unsigned long long, bool> values;
	int arr[n];
	vector<int> result;
	unsigned long long totalSum = 0;


	//lectura
	int x;
	for(int i = 0; i < n; i++){
		cin >> x;
		arr[i] = x;
		totalSum += x;
	}

	//precalcular
	for(int i = 0; i < n; i++){
		if(values.count(arr[i] * 2)) values[arr[i] * 2] = true;
		else values[arr[i] * 2] = false;
	}

	//sacar resultado
	unsigned long long posRes;
	for(int i = 0; i < n; i++){
		//si existe un numero
		posRes = totalSum - arr[i];
		if(values.count(posRes)){
			if(posRes == arr[i] * 2 && !values[posRes]) continue;
			result.push_back(i+1);
		}
	}

	//imprimir resultado
	cout << result.size() << "\n";
	for(int i = 0; i < result.size(); i++){
		cout << result[i] << "\n";
	}
}