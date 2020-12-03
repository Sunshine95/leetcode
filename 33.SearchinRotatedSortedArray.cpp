class Solution
{
public:
    int search(vector<int> &nums, int target)
    {

        int pivot = 0;
        while (pivot < nums.size() - 1 && nums[pivot] < nums[pivot + 1])
            pivot++;

        int i;

        i = lower_bound(nums.begin(), nums.begin() + pivot + 1, target) - nums.begin();
        if (i == nums.size())
            return -1;
        else if (nums[i] == target)
            return i;

        i = lower_bound(nums.begin() + pivot + 1, nums.end(), target) - nums.begin();
        if (i == nums.size())
            return -1;
        else if (nums[i] == target)
            return i;
        else
            return -1;
    }
};