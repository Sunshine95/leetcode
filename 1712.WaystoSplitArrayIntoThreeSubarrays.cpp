class Solution
{
public:
    int waysToSplit(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> prefix(n);

        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            prefix[i] = sum;
        }

        int count = 0;
        vector<int>::iterator c1, c2;

        for (int i = 0; i < n - 2; i++)
        {

            c1 = lower_bound(prefix.begin() + i + 1, prefix.end(), 2 * prefix[i]);
            c2 = upper_bound(prefix.begin() + i + 1, prefix.end() - 1, (prefix.back() + prefix[i]) / 2);

            if (c1 < c2)
            {
                count = (count + c2 - c1) % 1000000007;
            }
        }

        return count;
    }
};