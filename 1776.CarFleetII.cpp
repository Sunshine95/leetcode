class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        
        const int pos = 0, speed = 1;
        
        int n = cars.size();
        vector<double> answer(n,-1);
                
        vector<int> pile;
        pile.push_back(n-1);
        
        for(int i = n-2; i >= 0; i--){
            while(!pile.empty()){
                
                int j = pile.back();
                if(cars[j][speed] < cars[i][speed]){
                    
                    double t = 1.0 * (cars[j][pos] - cars[i][pos])/(cars[i][speed] - cars[j][speed]) ;
                    if(answer[j] == -1 || t <= answer[j] ){
                        answer[i] = t;
                        break;
                    }
                }           
                pile.pop_back();
            }
            
            pile.push_back(i);
        }
        
        return answer;
        
    }
};