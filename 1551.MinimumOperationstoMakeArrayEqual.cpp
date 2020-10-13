class Solution
{
public:
    int minOperations(int n)
    {

        int p = n >> 1;

        if (n & 1)
        {
            return p * (p + 1);
        }
        else
        {
            return p * p;
        }
    }
};