#include<bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode * bit[2] = {NULL, NULL};
};

void insert(int l, TrieNode* root){
    cout << "insert " << l << ": ";
    for(int i = 31; i >= 0; i--){
        
        int b = (l>>i) & 1;
        cout << b;

        if(root->bit[b] == NULL){
            root->bit[b] = new TrieNode();
        }
        
        root = root->bit[b];
    }
    cout << "\n";

    return;        
}

static bool sortHelp(vector<int> a, vector<int> b){
    return a[1] < b[1] ;
}

vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    
    vector<int> mX(queries.size(), -1);
    
    for(int i = 0; i < queries.size(); i++){
        queries[i].push_back(i);
    }
    
    sort(nums.begin(), nums.end());
    sort(queries.begin(), queries.end(), sortHelp);
    
    TrieNode *root = new TrieNode();
    
    int j = 0;
    for(int i = 0; i < queries.size(); i++){

        while(j < nums.size() && nums[j] <= queries[i][1]){
            insert(nums[j], root);
            j++;
        }
        
        if(j == 0) continue;
        
        TrieNode * temp = root;            
        int l = queries[i][0];
        cout << "find max XOR with " << l << "\n";
        long int x = 0;
        
        for(int k = 31; k >= 0; k--){
            int b = (l>>k) & 1;
            
            if(temp->bit[!b] != NULL){
                cout << !b;
                temp = temp->bit[!b];
                x += (1<<k);
            }
            else{
                cout << b;
                temp = temp->bit[b];
            }
        }
        cout << ": " << x << "\n";
        
        mX[queries[i][2]] = x;
    }
    
    return mX;
}

int main(){

    vector<int> nums = {5, 2, 4, 6, 6, 3};
    vector<vector<int>> queries = {{12, 4}, {8, 1}, {6, 3}};

    maximizeXor(nums, queries);

    return 0;
}