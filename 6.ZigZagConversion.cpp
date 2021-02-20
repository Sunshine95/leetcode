class Solution
{
public:
    string convert(string s, int numRows)
    {

        if (numRows == 1)
            return s;

        int n = numRows + numRows - 2;
        string t;

        // j = 0
        for (int i = 0; i < s.size(); i += n)
        {
            t += s[i];
        }

        for (int j = 1; j < numRows - 1; j++)
        {
            for (int i = j; i < s.size(); i += n)
            {
                t += s[i];
                if (i + n - 2 * j < s.size())
                    t += s[i + n - 2 * j];
            }
        }

        // j = numRow-1
        for (int i = numRows - 1; i < s.size(); i += n)
        {
            t += s[i];
        }

        return t;
    }
};