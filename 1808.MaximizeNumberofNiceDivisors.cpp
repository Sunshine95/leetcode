#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    const int MOD = 1000000007;
    
    long int modPower3(int exp){

        long int BASE = 3;
        
        long int ans = 1;
        while(exp){
            
            if(exp&1){
                ans = ((ans) * (BASE)) % MOD;
            }
            
            BASE = ((BASE) * (BASE)) % MOD;            
            exp = exp >> 1;
            
        }
        
        return ans;
        
    }
    
    int maxNiceDivisors(int n) {
        
        if(n == 1)
            return 1;
        
        if(n == 2)
            return 2;
        
        if(n == 3)
            return 3;
        
        int out;
        switch(n%3){
                
            case 0:
                return modPower3(n/3);
                break;
                
            case 1:
                out = ((modPower3((n/3)-1) * 4) % MOD);
                return out;
                break;
                
            case 2:
                out = (modPower3(n/3) * 2) % MOD;
                return out;
                break;
                
        }
        
        return -1;  
        
    }
};