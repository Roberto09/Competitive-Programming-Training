#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Compare
{
public:
    bool operator() (pair<int, int> a, pair<int, int> b)
    {
    	return a.second > b.second;
    }
};

void printResult(vector<pair<int, int>> &vec, int n, int k){

	for(int i = 0, iK = 0; iK < k; i++){
		for(int j = 0; j < vec[i].second/n && iK < k; j++, iK++){
			cout << vec[i].first << "\n";
		}
	}
}

bool canMakeNCopies(int size, vector<pair<int, int>> &vec, int n, int k){
	int usedSpace = 0;
	for(int i = 0; i < size; i++){
		usedSpace += (vec[i].second  / n);
		if(usedSpace >= k) return true;
	}
	return false;
}


void generateResult(int k, vector<pair<int, int>> &vec){
	int size = vec.size() < k ? vec.size() : k;
	int l = 1, r = vec[0].second , mid;

	int mostCopies = 1;

	while(l<=r){
	//cout << "r: " << r << "l: " << l << endl;
		//cout << "enter" << endl;
		mid = l + (r-l)/2;
		if(canMakeNCopies(size, vec, mid, k)){
			//cout << "mostCopiesPosible: " << mid << endl;
			mostCopies = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	printResult(vec, mostCopies, k);
}

int main(){
	int n, k;
	cin >> n >> k;
	unordered_map<int, int> mp;
	vector<pair<int, int>> vec;

	int x;
	for(int i = 0; i < n; i++){
		cin >> x;
		if(mp.count(x)) mp[x] ++;
		else mp[x] = 1;
	}

	for (pair<const int,int>& p: mp)	vec.push_back(p);

	sort(vec.begin(), vec.end(), Compare());

	generateResult(k, vec);
	return 0;
}