//128. Longest Consecutive Sequence
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {

        unordered_set<int> set(nums.begin(), nums.end());
        int streak = 0;
        int lstreak = 0;

        for (int i : set)
        {
            if (set.find(i - 1) == set.end())
            {
                streak = 1;
                while (set.find(++i) != set.end())
                    streak++;
            }
            lstreak = max(streak, lstreak);
        }

        return lstreak;
    }
};