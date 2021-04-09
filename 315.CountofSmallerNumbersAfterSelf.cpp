class Solution {
public:
    
    struct treeNode{
      
        treeNode* left = NULL;
        treeNode* right = NULL;
        
        int val;        
        int leftCount = 0;
        
    };
    
    vector<int> countSmaller(vector<int>& nums) {
        
        treeNode* root = NULL;        
        if(!nums.size()) return vector<int>{};
        
        int n = nums.size();
        root = new treeNode();
        root->val = nums[n-1];
                
        treeNode* iti = root;        
        vector<int> count(n, 0);
        count[n-1] = 0;
        
        if(n == 1) return count;
        for(int i = n-2 ; i >= 0; i--){
            
            treeNode* temp = new treeNode();
            temp->val = nums[i];
            temp->leftCount = 0;
            
            iti = root;
            while(iti != NULL){
                
                if(temp->val > iti->val){
                    temp->leftCount += (iti->leftCount + 1);
                    if(iti->right != NULL){
                        iti = iti->right;
                    }
                    else{
                        iti->right = temp;
                        count[i] = temp->leftCount;
                        temp->leftCount = 0;
                        iti = NULL;
                    }
                }
                else{
                    iti->leftCount++;
                    if(iti->left != NULL){
                        iti = iti->left;
                    }
                    else{
                        iti->left = temp;
                        count[i] = temp->leftCount;
                        temp->leftCount = 0;
                        iti = NULL;
                    }
                }
            }         
        }
        
        return count;       
    }
};