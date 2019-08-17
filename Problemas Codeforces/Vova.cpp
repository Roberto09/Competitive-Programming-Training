#include <iostream>
using namespace std;

int main(){
	int n, r;
	cin >> n >> r;
	bool arr[n];
	int x;
	for(int i = 0; i < n; i++){
		cin >> x;
		if(x) arr[i] = true;
		else arr[i] = false;
	}

	int counter = 0;
	int lastOneBeforeOn = -1;
	r--;

	for(int i = 0; i < n; i++){
		if(arr[i]) lastOneBeforeOn = i;
		else{
			int first = -1, second = -1;
			int lastPosRight = i+r >= n ? n-1 : i+r;
				//si encuentra algo si se puede, de lo contrario te fijas a la izquierda
				for(int j = i+1; j <= lastPosRight; j++){
					if(arr[j]){
						first = second;
						second = j;
					}
				}
				// si se pudo
				if(second != -1){
					counter ++;
					i = lastPosRight;
					if(first != -1) lastOneBeforeOn = first;
				}
				//no se pudo
				else{
					//no se pudo;
					if(lastOneBeforeOn == -1){
						cout << -1 << "\n";
						return 0;
					}
					//checamos si se puede
					else{
						if(lastOneBeforeOn + r >= i){
							counter ++;
							i = lastOneBeforeOn + r;
							lastOneBeforeOn = -1;
						}
						else{
							cout << -1 << "\n";
							return 0;
						}
					}
				}
			}
		}
		cout << counter << "\n";
		return 0;
	}