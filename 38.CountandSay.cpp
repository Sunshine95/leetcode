class Solution
{
public:
    string countAndSay(int n)
    {

        if (n == 1)
        {
            return "1";
        }

        string s = countAndSay(n - 1);
        string t = "";

        char d = s[0];
        int count = 1;

        for (int i = 1; i < s.size(); i++)
        {

            if (s[i] == d)
            {
                count++;
            }
            else
            {
                t += (count + '0');
                t += d;

                d = s[i];
                count = 1;
            }
        }

        t += (count + '0');
        t += d;

        return t;
    }
};