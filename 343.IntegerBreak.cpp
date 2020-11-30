class Solution
{
public:
    long long int integerBreak(int n)
    {

        int MOD = 1000000007;

        if (n == 1)
            return 1;

        if (n == 2)
            return 1;

        if (n == 3)
            return 2;

        switch (n % 3)
        {

        case 0:
            return ((int)pow(3, n / 3)) % MOD;
            break;

        case 1:
            return ((int)pow(3, ((int)(n / 3)) - 1) * 2 * 2) % MOD;
            break;

        case 2:
            return ((int)pow(3, (int)(n / 3)) * 2) % MOD;
        }

        return -1;
    }
};