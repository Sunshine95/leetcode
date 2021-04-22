class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {

        int n = nums.size();

        int hi = INT_MIN;
        int cHi = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= hi)
            {
                hi = nums[i];
            }
            else
            {
                cHi++;
            }
        }

        int lo = INT_MAX;
        int cLo = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] <= lo)
            {
                lo = nums[i];
            }
            else
            {
                cLo++;
            }
        }

        return (cHi <= 1 || cLo <= 1);
    }
};