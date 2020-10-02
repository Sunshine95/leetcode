//1673. Find the Most Competitive Subsequence

class Solution
{
public:
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {

        int n = nums.size();
        vector<int> incSeq;

        for (int i = 0; i < n; i++)
        {

            while (!incSeq.empty() && incSeq.size() + (n - i) > k && nums[i] < incSeq.back())
            {
                incSeq.pop_back();
            }

            incSeq.push_back(nums[i]);
        }

        return vector<int>(incSeq.begin(), incSeq.begin() + k);
    }
};