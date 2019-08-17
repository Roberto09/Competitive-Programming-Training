#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;
int MAX = 10000000;

struct node{
	int normal = 0;
	int lazy = 0;
};

//construct -> O(n)   size -> O(n)
void constructTree(int arr[], node segment[], int low, int high, int pos){
	if(low == high){
		segment[pos].normal = arr[low];
		return;
	}
	int mid = low + (high-low)/2;
	constructTree(arr, segment, low, mid, 2*pos+1);
	constructTree(arr, segment, mid+1, high, 2*pos+2);
	segment[pos].normal = segment[2*pos+1].normal < segment[2*pos+2].normal ? segment[2*pos+1].normal : segment[2*pos+2].normal;
}

//query -> log2(n) returns min
int query (node segment[], int qlow, int qhigh, int low, int high, int pos){
	if(segment[pos].lazy != 0){
		segment[pos].normal += segment[pos].lazy;
		if(low != high){
			segment[2*pos+1].lazy += segment[pos].lazy;
			segment[2*pos+2].lazy += segment[pos].lazy;
		}
		segment[pos].lazy = 0;
	}
	//no ovelap
	if(high < qlow || low > qhigh) return MAX;
	// total overlap
	if(low >= qlow && high <= qhigh) return segment[pos].normal;
	//partial ovelap
	int mid = low + (high-low)/2;
	int left = query(segment, qlow, qhigh, low, mid, 2*pos+1);
	int right = query(segment, qlow, qhigh, mid+1, high, 2*pos+2);
	segment[pos].normal = left < right ? left: right;
}
//change range of values
//worst case -> O(log2 n)
void changeRangeOfValues(node segment[], int qlow, int qhigh, int sum, int low, int high, int pos){
	//ensure all propagation is done at the actual position
	if(segment[pos].lazy != 0){
		segment[pos].normal += segment[pos].lazy;
		if(low != high){
			segment[2*pos+1].lazy += segment[pos].lazy;
			segment[2*pos+2].lazy += segment[pos].lazy;
		}
		segment[pos].lazy = 0;
	}

	//no overlap
	if(high < qlow || low > qhigh) return;

	// total overlap
	if(low >= qlow && high <= qhigh){
		segment[pos].normal += sum;
		if(low != high){
			segment[2*pos+1].lazy += sum;
			segment[2*pos+2].lazy += sum;
		}
		return;
	}

	//partial overlap
	int mid = low + (high-low) / 2;
	changeRangeOfValues(segment, qlow, qhigh, sum, low, mid, 2*pos+1);
	changeRangeOfValues(segment, qlow, qhigh, sum, mid+1, high, 2*pos+2);
	segment[pos].normal = segment[2*pos+1].normal < segment[2*pos+2].normal ? segment[2*pos+1].normal : segment[2*pos+2].normal;
}

int main(){
	int N = 6, lenSeg;
	lenSeg = (int) 2 * pow(2.0, ceil(log((double) N) / log(2.0))) - 1;
	
	int arr[] = {-1,3,4,0,2,1};
	node segment[lenSeg];

	memset(segment, MAX, sizeof(segment[0]));
	
	constructTree(arr, segment, 0, N-1, 0);

	return 0;
}