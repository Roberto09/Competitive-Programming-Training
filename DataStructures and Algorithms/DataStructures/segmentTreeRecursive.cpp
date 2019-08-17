#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;
int MAX = 10000000;


//construct -> O(n)   size -> O(n)
void constructTree(int arr[], int segment[], int low, int high, int pos){
	if(low == high){
		segment[pos] = arr[low];
		return;
	}
	int mid = low + (high-low)/2;
	constructTree(arr, segment, low, mid, 2*pos+1);
	constructTree(arr, segment, mid+1, high, 2*pos+2);
	segment[pos] = segment[2*pos+1] < segment[2*pos+2] ? segment[2*pos+1] : segment[2*pos+2];
}

//query -> log2(n) returns min
int query (int segment[], int qlow, int qhigh, int low, int high, int pos){
	//no overlap
	if(high < qlow || low > qhigh) return MAX;
	//total overlap 
	else if(low >= qlow && high <= qhigh) return segment[pos];
	//partial ovelap
	else{
		int mid = low + (high-low)/2;
		int left = query(segment, qlow, qhigh, low, mid, 2*pos +1);
		int right = query(segment, qlow, qhigh, mid+1, high, 2*pos +2);
		return left < right ? left : right; 
	}
}

//change number at N position for X -> log2(n)
void changeNumberAtNPosition(int segment[], int arr[], int arrHigh, int N, int X){
	arr[N] = X;
	//get to number and change it
	int low = 0, high = arrHigh, mid, pos = 0;
	while(low != high){
		mid = low + (high - low)/2;
		//left
		if(N <= mid){
			high = mid; pos = 2*pos + 1;
		}
		//right
		else{
			low = mid + 1; pos = 2*pos + 2;
		}
	}
	segment[pos] = X;
	// go backwards
	int prev = pos, left, right;
	while(prev > 0){
		prev = (prev-1) / 2;
		left = segment[2*prev+1];
		right = segment[2*prev+2];
		//si el menor es igual aun que cambiemos el numero paramos
		if(segment[prev] == (left < right ? left : right))	break;
		// ponemos el menor
		segment[prev] = left < right ? left : right;
	}
}

//change range of values
//worst case -> O(range)
void changeRangeOfValues(int segment[], int ql, int qh, int sum, int low, int high, int pos){
	if(low > high || ql > high || qh < low)
		return;

	if(low == high){
		segment[pos] += sum;
		return;
	}

	int mid = low + (high - low)/2;
	changeRangeOfValues(segment, ql, qh, sum, low, mid, 2*pos+1);
	changeRangeOfValues(segment, ql, qh, sum, mid+1, high, 2*pos+2);
	segment[pos] = segment[2*pos+1] < segment[2*pos+2] ? segment[2*pos+1] : segment[2*pos+2];
}

int main(){
	int N = 6, lenSeg;
	lenSeg = (int) 2 * pow(2.0, ceil(log((double) N) / log(2.0))) - 1;
	
	int arr[] = {-1,3,4,0,2,1};
	int segment[lenSeg];

	memset(segment, MAX, sizeof(segment[0]));
	
	constructTree(arr, segment, 0, N-1, 0);

	int x, y;
	while(x != -1){
		cin >> x >> y;
		cout << query(segment, x, y, 0, N-1, 0) << endl;
	}


	cout << "number" << endl;
	cin >> x >> y;
	changeNumberAtNPosition(segment, arr, N, x, y);

	cout << endl << "el segment es: " << endl;
	for(int i = 0; i < lenSeg; i++) cout << segment[i] << " ";
	cout << endl;

	while(x != -1){
		cin >> x >> y;
		cout << query(segment, x, y, 0, N-1, 0) << endl;
	}


	return 0;
}