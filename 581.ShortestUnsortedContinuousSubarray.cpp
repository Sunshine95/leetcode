class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int lo, hi;
        int sort_max_index, sort_min_index;

        hi = INT_MIN;
        sort_max_index = -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > hi)
            {
                hi = nums[i];
            }
            else if (nums[i] < hi)
            {
                sort_max_index = i;
            }
        }

        lo = INT_MAX;
        sort_min_index = n;
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] < lo)
            {
                lo = nums[i];
            }
            else if (nums[i] > lo)
            {
                sort_min_index = i;
            }
        }

        if (sort_min_index <= sort_max_index)
        {
            return sort_max_index - sort_min_index + 1;
        }
        else
        {
            return 0;
        }
    }
};