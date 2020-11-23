class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {

        int n = nums.size();
        vector<int> score(n);
        deque<int> dq;

        score[0] = nums[0];
        dq.push_back(0);

        for (int i = 1; i < n; i++)
        {

            while (!dq.empty() && dq.front() < i - k)
            {
                dq.pop_front();
            }

            score[i] = nums[i] + score[dq.front()];

            while (!dq.empty() && score[dq.back()] < score[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        return score[n - 1];
    }
};