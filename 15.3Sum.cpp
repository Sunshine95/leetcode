class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        int n = nums.size();
        int x, y, z;
        sort(nums.begin(), nums.end());
        vector<vector<int>> triplets(0);

        if (n < 3)
            return triplets;

        for (auto i = nums.begin(); i != nums.end() - 2; i++)
        {

            if (*i > 0)
                break;

            x = *i;
            for (auto j = i + 1; j != nums.end() - 1; j++)
            {

                y = *j;
                z = -1 * (x + y);

                if (binary_search(j + 1, nums.end(), z))
                {

                    triplets.push_back(vector<int>{x, y, z});
                }

                while (*j == *(j + 1) && j != nums.end() - 2)
                    j++;
            }

            while (*i == *(i + 1) && i != nums.end() - 3)
                i++;
        }

        return triplets;
    }
};