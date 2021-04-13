class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        
        stack<int> s;
        vector<int> left(n);
        vector<int> right(n);
        
        
        for(int i = 0; i < n; i++){
            
            if(s.empty() || heights[i] > heights[s.top()]){
                left[i] = i;
            }
            else{
                while(!s.empty() && heights[i] <= heights[s.top()]){
                    s.pop();
                }
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
                while(!s.empty() && heights[i] <= heights[s.top()]){
             
                    s.pop();
                }
                right[i] = s.empty() ? n-1 : s.top()-1;
            }
            s.push(i);
        }
        
        int maxArea = -1;
        
        for(int i = 0; i < n; i++){
            maxArea = max(maxArea, heights[i] * (right[i] - left[i] + 1));
        }
        
        return maxArea;
    }
};