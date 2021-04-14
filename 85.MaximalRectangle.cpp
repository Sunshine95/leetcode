class Solution {
public:
    
    int Area(vector<int>& heights){
        
        int n = heights.size();
        
        stack<int> s;
        vector<int> left(n);
        vector<int> right(n);
        
        int area, maxArea = -1;
        
        for(int i = 0; i < n; i++){
            if(s.empty() || heights[i] > heights[s.top()]){
                left[i] = i;
            }
            else{
                while(!s.empty() && heights[i] <= heights[s.top()]) s.pop();
                left[i] = s.empty() ? 0 : s.top()+1;
            }           
            s.push(i);
        }
        
        while(!s.empty()) s.pop();
        
        for(int i = n-1; i >= 0; i--){
            if(s.empty() || heights[i] > heights[s.top()]){
                right[i] = i;
            }
            else{
                while(!s.empty() && heights[i] <= heights[s.top()]) s.pop();
                right[i] = s.empty() ? n-1 : s.top()-1;
            }
            s.push(i);
        }
        
        for(int i = 0; i < n; i++){
            area = heights[i] * (right[i] - left[i] + 1);
            maxArea = max(area, maxArea);
        }
        
        return maxArea;        
    }
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        if(!n) return 0;
        int m = matrix[0].size();
        
        vector<int> v(m, 0);
        int maxArea = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                v[j] = (matrix[i][j] == '0') ? 0 : (v[j] + 1); 
            }
            maxArea = max(Area(v), maxArea); 
        }
        
        return maxArea;        
    }
};