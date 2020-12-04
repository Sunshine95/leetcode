class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {

        vector<long int> totals(amount + 1, INT_MAX);
        totals[0] = 0;

        for (long int c : coins)
        {
            if (c <= amount)
                totals[c] = 1;
        }

        for (long int i = 1; i <= amount; i++)
        {
            for (long int c : coins)
            {
                if (totals[i] != INT_MAX && i + c <= amount)
                {
                    totals[i + c] = min(totals[i + c], totals[i] + 1);
                }
            }
        }

        if (totals[amount] == INT_MAX)
            return -1;

        return totals[amount];
    }
};