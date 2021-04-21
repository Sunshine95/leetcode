//29. Divide Two Integers
class Solution
{
public:
    int divide(int dividend, int divisor)
    {

        long long did = dividend;
        long long div = divisor;
        long long q = did / div;

        q = (q >= 2147483648) ? 2147483647 : q;
        return q;

        //         if(dividend == 0) return 0;
        //         if(dividend == divisor) return 1;
        //         // cannot use *, /, %

        //         int product = 0;
        //         int quotient = 0;

        //         // remainder = divident - (divisor * quotient)
        //         // remainder < divisor

        //         if(dividend > 0){
        //             if(divisor > 0){
        //                 while((product) < dividend){
        //                     product += divisor;
        //                     quotient += 1;
        //                 }
        //                 quotient--;
        //             }
        //             else{
        //                 divisor = abs(divisor);
        //                 while((product) < dividend){
        //                     product += divisor;
        //                     quotient += 1;
        //                 }
        //                 quotient--;
        //                 quotient = -quotient;
        //             }
        //         }
        //         else{
        //             if(divisor > 0){
        //                 divisor = -divisor;
        //                 while((product) < dividend){
        //                     product += divisor;
        //                     quotient += 1;
        //                 }
        //                 quotient--;
        //                 quotient = -quotient;
        //             }
        //             else{
        //                 while((product) < dividend){
        //                     product += divisor;
        //                     quotient += 1;
        //                 }
        //                 quotient--;
        //             }
        //         }

        //         return quotient;
    }
};