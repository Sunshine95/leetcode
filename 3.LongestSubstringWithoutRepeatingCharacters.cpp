class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        if (s.empty())
            return 0;

        vector<int> hash(255, -1);
        int i = 0;
        int j = 0;
        int maxLen = 1;

        for (j = 0; j < s.size(); j++)
        {

            int c = s[j];

            if (hash[c] >= i)
            {
                i = hash[c] + 1;
            }

            maxLen = max(maxLen, j - i + 1);
            hash[c] = j;
        }

        return maxLen;
    }
};