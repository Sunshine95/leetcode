class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {

        int n = nums.size();
        vector<int> z{-1, -1};
        vector<int> range(2);

        range[0] = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        if (range[0] >= n || nums[range[0]] != target)
            return z;

        range[1] = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        range[1]--;

        return range;
    }
};