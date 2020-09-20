class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {

        int n = groupSizes.size();
        vector<vector<int>> bucket(n + 1);
        vector<vector<int>> out;

        for (int i = 0; i < n; i++)
        {
            bucket[groupSizes[i]].push_back(i);
        }

        for (int i = 1; i < n + 1; i++)
        {
            int c = i;
            while (bucket[i].size() >= c)
            {
                out.push_back(vector<int>(bucket[i].begin() + (c - i), bucket[i].begin() + c));
                c += i;
            }
        }

        return out;
    }
};