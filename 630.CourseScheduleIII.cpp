class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort(courses.begin(), courses.end(), [](auto& a, auto &b){return a.back() < b.back();});
        priority_queue<int> q;
        
        int sum = 0;
        for(int i = 0; i < courses.size(); i++){
            
            sum += courses[i][0];
            q.push(courses[i][0]);
            
            if(sum > courses[i][1]){
                sum -= q.top();
                q.pop();
            }           
        }
        
        return q.size();
    }
};