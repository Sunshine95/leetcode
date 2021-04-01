#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        
        int maxLen = 0;
        stack<int> prev;
        prev.push(-1);
        
        for(int i = 0; i < s.size(); i++){
            
            if(s[i] == '('){
                prev.push(i);
            }
            else{
                
                prev.pop();
                
                if(!prev.empty()){
                    maxLen = max(maxLen, i-prev.top());
                }
                else{
                    prev.push(i);
                }                
            }            
        }
        
        return maxLen;
    }
};