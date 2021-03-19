#include<bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int>& nums){

    int n = nums.size();
    int i;

    for(i = 0; i < n; i++){
        while(!(nums[i] < 1 || nums[i] > n || (nums[i] - 1 == i || nums[nums[i]-1] == nums[i]))){
            swap(nums[nums[i]-1], nums[i]);
        }
    }
    for(i = 0; i < n; i ++){
        if(nums[i] - 1 != i){
            break;
        }
    }
    return i + 1;
}


int main(){

    int T;
    cin >> T;

    int n;
    int x;
    vector<int> nums;
    while(T--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> x;
            nums.push_back(x);
        }

        cout << firstMissingPositive(nums) << endl;
        nums.clear();
    }

    return 0;
}