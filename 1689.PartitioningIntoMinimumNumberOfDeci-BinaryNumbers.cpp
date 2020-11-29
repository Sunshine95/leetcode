class Solution
{
public:
    int minPartitions(string n)
    {

        int ans = -1;
        for (int i = 0; i < n.size(); i++)
        {
            ans = max(ans, n[i] - '0');
        }

        if (ans <= 1)
        {
            return 1;
        }

        return ans;
    }
};