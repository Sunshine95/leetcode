class Solution
{
public:
    int uniquePaths(int m, int n)
    {

        if (m == 1 || n == 1)
        {
            return 1;
        }

        long long int i = max(m, n) - 1;
        long long int j = min(m, n) - 1;
        long long int ans = 1;

        for (int x = 1; x <= j; x++)
        {
            ans *= (i + x);
        }
        for (int x = 1; x <= j; x++)
        {
            ans /= (x);
        }

        return ans;
    }
};