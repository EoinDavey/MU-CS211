#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; i++){
		cin >> nums[i];
	}
	sort(nums.begin(),nums.end());
	int mini = 1000000000;
	while(nums.size() > 1){
		int smallest_gap_index = 0;
		int smallest_gap_value = 100000000;
		for(int i = 0; i < nums.size()-1; i++){
			if(abs(nums[i]-nums[i+1]) < smallest_gap_value){
				smallest_gap_value = abs(nums[i]-nums[i+1]);
				smallest_gap_index = i;
			}
		}
		nums.erase(nums.begin()+smallest_gap_index);
		nums.erase(nums.begin()+smallest_gap_index);
		nums.push_back(smallest_gap_value);
		if(mini > smallest_gap_value)mini = smallest_gap_value;
		sort(nums.begin(),nums.end());
		for(int i = 0; i < nums.size(); i++){
			cout << nums[i] << ' ';
		}
		cout << endl;
	}
	cout << mini << endl;
}
