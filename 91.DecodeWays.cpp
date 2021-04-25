class Solution
{
public:
    int count;
    vector<int> memo;

    bool backtrack(int pos, string &s)
    {

        if (pos < 0)
        {
            count++;
            return true;
        }

        if (memo[pos] != -1)
        {
            count += memo[pos];
            return true;
        }

        int c = s[pos] - '0';

        if (c == 0)
        {
            // invalid
            if (pos == 0 || (s[pos - 1] != '1' && s[pos - 1] != '2'))
            {
                return false;
            }
            //'J', 'T';
            backtrack(pos - 2, s);
        }
        else if (c <= 9 && c >= 7)
        {
            //'G', 'H', 'I';
            if (!backtrack(pos - 1, s))
            {
                return false;
            }

            if (pos - 1 >= 0 && s[pos - 1] == '1')
            {
                //'Q', 'R', 'S';
                if (!backtrack(pos - 2, s))
                {
                    return false;
                }
            }
        }
        else
        {
            //'A', 'B', 'C', 'D', 'E', 'F';
            if (!backtrack(pos - 1, s))
            {
                return false;
            }

            if (pos - 1 >= 0 && s[pos - 1] == '1')
            {
                //'K', 'L', 'M', 'N', 'O', 'P';
                if (!backtrack(pos - 2, s))
                {
                    return false;
                }
            }
            else if (pos - 1 >= 0 && s[pos - 1] == '2')
            {
                //'U', 'V', 'W', 'X', 'Y', 'Z';
                if (!backtrack(pos - 2, s))
                {
                    return false;
                }
            }
        }

        memo[pos] = count;
        return true;
    }

    int numDecodings(string s)
    {

        int n = s.size();
        count = 0;
        memo.resize(n, -1);

        if (!backtrack(n - 1, s))
        {
            return 0;
        }
        return count;
    }
};