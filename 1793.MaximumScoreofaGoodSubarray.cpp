//1793. Maximum Score of a Good Subarray
class Solution
{
public:
    int maximumScore(vector<int> &nums, int k)
    {

        int n = nums.size();

        stack<int> stk;
        vector<int> left(n);
        vector<int> right(n);

        for (int i = 0; i < n; i++)
        {

            while (!stk.empty() && nums[stk.top()] >= nums[i])
            {
                stk.pop();
            }

            left[i] = stk.empty() ? 0 : stk.top() + 1;

            stk.push(i);
        }

        while (!stk.empty())
            stk.pop();

        for (int i = n - 1; i >= 0; i--)
        {

            while (!stk.empty() && nums[stk.top()] >= nums[i])
            {
                stk.pop();
            }

            right[i] = stk.empty() ? n - 1 : stk.top() - 1;

            stk.push(i);
        }

        int score, maxScore = -1;
        for (int i = 0; i < n; i++)
        {
            if (left[i] <= k && k <= right[i])
            {
                score = (right[i] - left[i] + 1) * nums[i];
                maxScore = max(score, maxScore);
            }
        }

        return maxScore;
    }
};