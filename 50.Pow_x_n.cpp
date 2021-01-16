class Solution {
public:
double myPow(double x, long long int n) {
    
    if(n == 0){
        return 1;
    }
    else if(n < 0){
        x = 1/x;
        n *= -1;
    }

    long double res = 1;

    while(n){
        if(n & 1){
            res *= x;
        }
        x *= x;
        n >>= 1;

    }

    return res;
        
}
};