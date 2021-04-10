class Solution {
public:
    
    int pathLen(vector<vector<int>>& matrix, vector<vector<int>>& mem, int i, int j){
        
        int len = mem[i][j];
        if(len != 0) return len;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        len = 1;
        if(j < n-1 && matrix[i][j] > matrix[i][j+1]){
            len = max( pathLen(matrix, mem, i, j+1) + 1, len);
            
        }
        if(i < m-1 && matrix[i][j] > matrix[i+1][j]){
            len = max( pathLen(matrix, mem, i+1, j) + 1, len);
        }
        if(j > 0 && matrix[i][j] > matrix[i][j-1]){
            len = max( pathLen(matrix, mem, i, j-1) + 1, len);
        }
        if(i > 0 && matrix[i][j] > matrix[i-1][j]){
            len = max( pathLen(matrix, mem, i-1, j) + 1, len);
        }
        
        mem[i][j] = len;
        return len;
        
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        if(!matrix.size()) return 0;
        
        int maxPath = INT_MIN;
        vector<vector<int>> memory(matrix.size(), vector<int>(matrix[0].size(), 0));
        
        
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                maxPath = max(pathLen(matrix, memory, i, j), maxPath);
            }
        }
        
        return maxPath;
    }
};