class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {

        int n = nums.size();
        vector<int> hash(n, 0);

        for (int i : nums)
        {
            hash[i]++;
            if (hash[i] > 1)
                return i;
        }

        return -1;
    }
};