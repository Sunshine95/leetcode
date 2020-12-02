class Solution
{
public:
    vector<int> countBits(int num)
    {

        vector<int> out;

        for (int i = 0; i <= num; i++)
            out.push_back(__builtin_popcount(i));

        return out;
    }
};