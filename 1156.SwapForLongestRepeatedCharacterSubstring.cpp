class Solution
{
public:
    int maxRepOpt1(string text)
    {

        int n = text.size();
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);
        vector<int> hash(26, 0);
        int len, maxLen;
        bool repeat = false;

        for (int i = 0; i < n; i++)
        {
            hash[text[i] - 'a']++;
            if (hash[text[i] - 'a'] > 1)
                repeat = true;
        }

        if (!repeat)
            return 1;
        maxLen = 2;

        prefix[0] = 1;
        for (int i = 1; i < n; i++)
        {
            char c = text[i];
            if (c == text[i - 1])
            {
                prefix[i] = prefix[i - 1] + 1;
            }
            else
            {
                prefix[i] = 1;
            }

            len = min(prefix[i - 1] + 1, hash[text[i - 1] - 'a']);
            maxLen = max(maxLen, len);
        }

        suffix[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            char c = text[i];
            if (c == text[i + 1])
            {
                suffix[i] = suffix[i + 1] + 1;
            }
            else
            {
                suffix[i] = 1;
            }

            len = min(suffix[i + 1] + 1, hash[text[i + 1] - 'a']);
            maxLen = max(maxLen, len);
        }

        for (int i = 1; i < n - 1; i++)
        {
            if (text[i - 1] == text[i + 1])
            {
                len = min(prefix[i - 1] + suffix[i + 1] + 1, hash[text[i - 1] - 'a']);
                maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
};