class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {

        if (!x)
            return 0;

        int n = nums.size();
        int len = n + 1;
        int xComp = accumulate(nums.begin(), nums.end(), 0) - x;

        if (!xComp)
            return n;

        int i, j, sum = 0;

        i = j = 0;
        while (j < n)
        {
            sum += nums[j++];

            while (i < j && sum > xComp)
            {
                sum -= nums[i++];
            }

            if (sum == xComp)
            {
                len = min(len, n - (j - i));
            }
        }

        if (len < n)
        {
            return len;
        }
        else
        {
            return -1;
        }
    }
};