class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        permute(result, nums, 0);
        return result;
    }

private:
    void permute(vector<vector<int>> &result, vector<int> nums, int pos)
    {

        if (pos == nums.size())
        {
            result.push_back(nums);
            return;
        }

        for (int j = pos; j < nums.size(); j++)
        {
            swap(nums[j], nums[pos]);
            permute(result, nums, pos + 1);
        }
        return;
    }
};