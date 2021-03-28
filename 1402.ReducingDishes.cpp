class Solution
{
public:
    int maxSatisfaction(vector<int> &satisfaction)
    {

        int prefix = 0;
        int likeSum = 0;
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());

        int i = 0;
        while (i < satisfaction.size() && (prefix + satisfaction[i]) >= 0)
        {
            likeSum += (prefix + satisfaction[i]);
            prefix += satisfaction[i];
            i++;
        }

        return likeSum;
    }
};