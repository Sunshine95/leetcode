#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidWin(vector<int>& nums, int k){

    deque<int> dq;
    vector<int> res;

    for(int i = 0; i < k; i++){
        while(!dq.empty() && nums[dq.back()] < nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }

    res.push_back(nums[dq.front()]);

    for(int i = k; i < nums.size(); i++){
        
        if(dq.front() < i - k + 1){
            dq.pop_front();
        }

        while(!dq.empty() && nums[dq.back()] < nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);

        res.push_back(nums[dq.front()]);
    }

    return res;
}



int main(){

    int T;
    
    int n;
    vector<int> nums;
    int k;
    
    vector<int> res;

    int x;

    cin >> T;
    while(T--){

        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> x;
            nums.push_back(x);
        }

        cin >> k;

        res = maxSlidWin(nums, k);
        for(int i : res){
            cout << i << " ";
        }
        cout << endl;

        nums.clear();
    }

    return 0;
}