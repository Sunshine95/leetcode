class Solution
{
public:
    vector<vector<int>> out;

    void backtrack(vector<int> &nums, int index)
    {

        if (index == nums.size() - 1)
        {
            out.push_back(nums);
            return;
        }

        unordered_set<int> seen;
        for (int i = index; i < nums.size(); i++)
        {

            if (seen.find(nums[i]) != seen.end())
                continue;

            swap(nums[index], nums[i]);
            backtrack(nums, index + 1);
            swap(nums[index], nums[i]);

            seen.insert(nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {

        backtrack(nums, 0);
        return out;
    }
};