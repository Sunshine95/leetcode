class Solution
{
public:
    int minMoves(vector<int> &nums, int l)
    {

        int n = nums.size();
        vector<int> sumCount(2 * l + 2, 0); // 2->2*limit
        vector<int> range(2 * l + 2, 0);    //2->2*limit

        for (int i = 0; i < n / 2; i++)
        {

            range[1 + min(nums[i], nums[n - 1 - i])]++;
            range[l + max(nums[i], nums[n - 1 - i]) + 1]--;

            sumCount[nums[i] + nums[n - 1 - i]]++;
        }

        int inRange = 0;
        int moves = n;

        for (int i = 2; i < 2 * l + 2; i++)
        {

            inRange += range[i];
            int movesForI = ((n / 2 - inRange) * 2) + inRange - sumCount[i];

            moves = min(moves, movesForI);
        }

        return moves;
    }
};