class Solution
{
public:
    vector<vector<string>> partition(string s)
    {

        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int i, j;
        // preprocessing

        for (i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }

        for (j = 1; j < n; j++)
        {
            if (s[j - 1] == s[j])
            {
                dp[j - 1][j] = true;
            }
        }

        for (int size = 2; size < n; size++)
        {
            for (i = 0, j = size; j < n; i++, j++)
            {
                if (s[i] == s[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                }
            }
        }

        // bit operation to generate all partitions

        long int nPartition = pow(2, n - 1);
        vector<string> curList;
        vector<vector<string>> resultSet;

        for (i = 0; i < nPartition; i++)
        {

            int t = n;
            int p = i;
            int start = 0;
            int end = 0;

            curList.clear();

            while (t--)
            {
                if (p & 1)
                {
                    end++;
                }
                else
                {
                    if (dp[start][end])
                    {
                        curList.push_back(s.substr(start, end - start + 1));
                        start = end + 1;
                        end = start;
                    }
                    else
                    {
                        break;
                    }
                }

                p = p >> 1;
            }

            if (end == n)
                resultSet.push_back(curList);
        }

        return resultSet;
    }
};