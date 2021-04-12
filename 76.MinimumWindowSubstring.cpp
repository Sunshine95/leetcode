class Solution
{
public:
    string minWindow(string s, string t)
    {

        if (t.size() > s.size())
            return "";

        vector<int> thash(58, 0);
        vector<int> shash(58, 0);

        int count = 0;
        int l = 0;
        int r = 0;
        int winMin = s.size();
        string minSubStr = s;

        for (char tt : t)
        {
            thash[tt - 'A']++;
        }

        for (r = 0; r < s.size(); r++)
        {
            int ch = s[r] - 'A';

            shash[ch]++;
            if (thash[ch] != 0 && shash[ch] <= thash[ch])
                count++;

            if (count == t.size())
                break;
        }

        if (count < t.size())
            return "";

        int chL = s[l] - 'A';
        while (shash[chL] > thash[chL])
        {
            shash[chL]--;
            l++;
            chL = s[l] - 'A';
        }

        winMin = r - l + 1;
        minSubStr = s.substr(l, winMin);
        r++;

        for (; r < s.size(); r++)
        {

            int ch = s[r] - 'A';
            shash[ch]++;

            if (thash[ch] != 0 && shash[ch] > thash[ch])
            {

                chL = s[l] - 'A';
                while (shash[chL] > thash[chL])
                {
                    shash[chL]--;
                    l++;
                    chL = s[l] - 'A';
                }

                if (winMin > r - l + 1)
                {
                    winMin = r - l + 1;
                    minSubStr = s.substr(l, winMin);
                }
            }
        }

        return minSubStr;
    }
};