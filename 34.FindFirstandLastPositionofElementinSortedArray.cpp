class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {

        if (!nums.size())
            return vector<int>{-1, -1};

        int low;
        int high;

        low = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        if (low == nums.size() || nums[low] != target)
            return vector<int>{-1, -1};

        high = low;

        while (high < nums.size() && nums[high] == nums[low])
        {
            high++;
        }

        return vector<int>{low, high - 1};
    }
};