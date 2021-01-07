class Solution
{
public:
    string longestPalindrome(string s)
    {

        if (s.length() == 0)
        {
            return "";
        }

        int maxLength = 0;
        int length;
        int len1, len2;
        int l, r;

        l = 0;
        r = 0;
        for (int i = 0; i < s.length(); i++)
        {

            len1 = expandCentre(i, i, s);
            len2 = expandCentre(i, i + 1, s);
            length = max(len1, len2);

            if (maxLength < length)
            {

                if (length % 2)
                {
                    l = i - (length / 2);
                    r = i + (length / 2);
                }
                else
                {
                    l = i - (length / 2) + 1;
                    r = i + (length / 2);
                }
                maxLength = length;
            }
        }

        string palindrome(s.begin() + l, s.begin() + r + 1);
        return palindrome;
    }

    int expandCentre(int r, int l, string s)
    {

        while ((l > -1) && (r < s.length()) && (s[l] == s[r]))
        {
            l--;
            r++;
        }

        return r - l - 1;
    }
};