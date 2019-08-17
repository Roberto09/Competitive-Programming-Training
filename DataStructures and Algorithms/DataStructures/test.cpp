#include <iostream>
#include <string.h>
using namespace std;
int main(){
	int x = 10000;
	int arr[x] = {0};

	for(int i = 0; i < x; i++) cout << arr[i];
	return 0;
}