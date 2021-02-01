class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        
        vector<bool> out(queries.size());
        int n = candiesCount.size();
        vector<long long int> maxDay(n);
        long long int minDay;
        
        maxDay[0] = candiesCount[0];
        for(int i = 1; i < candiesCount.size(); i++){
            maxDay[i] = candiesCount[i] + maxDay[i-1];
        }
        
        for(int i = 0; i < queries.size(); i++){
            
            int type = queries[i][0];
            int day = queries[i][1];
            int cap = queries[i][2];
            
            minDay = type == 0 ? 0 : maxDay[type-1] / cap;
            
            out[i] = (minDay <= day && day < maxDay[type]);
                
        }            
        
        return out;
        
    }
};