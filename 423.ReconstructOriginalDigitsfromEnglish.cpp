class Solution
{
public:
    string originalDigits(string s)
    {

        vector<int> hash(26, 0);
        vector<int> digits(10, 0);

        for (char c : s)
        {
            hash[c - 'a']++;
        }

        while (hash['s' - 'a'] > 0 && hash['e' - 'a'] > 1 && hash['v' - 'a'] > 0 && hash['n' - 'a'] > 0)
        {
            digits[7]++;
            hash['s' - 'a']--;
            hash['e' - 'a'] -= 2;
            hash['v' - 'a']--;
            hash['n' - 'a']--;
        }

        while (hash['f' - 'a'] > 0 && hash['i' - 'a'] > 0 && hash['v' - 'a'] > 0 && hash['e' - 'a'] > 0)
        {
            digits[5]++;
            hash['f' - 'a']--;
            hash['i' - 'a']--;
            hash['v' - 'a']--;
            hash['e' - 'a']--;
        }

        while (hash['f' - 'a'] > 0 && hash['o' - 'a'] > 0 && hash['u' - 'a'] > 0 && hash['r' - 'a'] > 1)
        {
            digits[4]++;
            hash['f' - 'a']--;
            hash['o' - 'a']--;
            hash['u' - 'a']--;
            hash['r' - 'a']--;
        }

        while (hash['t' - 'a'] > 0 && hash['h' - 'a'] > 0 && hash['r' - 'a'] > 0 && hash['e' - 'a'] > 1)
        {
            digits[3]++;
            hash['t' - 'a']--;
            hash['h' - 'a']--;
            hash['r' - 'a']--;
            hash['e' - 'a'] -= 2;
        }

        while (hash['n' - 'a'] > 1 && hash['i' - 'a'] > 0 && hash['e' - 'a'] > 0)
        {
            digits[9]++;
            hash['n' - 'a'] -= 2;
            hash['i' - 'a']--;
            hash['e' - 'a']--;
        }

        while (hash['o' - 'a'] > 0 && hash['n' - 'a'] > 0 && hash['e' - 'a'] > 0)
        {
            digits[1]++;
            hash['o' - 'a']--;
            hash['n' - 'a']--;
            hash['e' - 'a']--;
        }

        while (hash['z' - 'a'] > 0 && hash['e' - 'a'] > 0 && hash['r' - 'a'] > 0 && hash['o' - 'a'] > 0)
        {
            digits[0]++;
            hash['z' - 'a']--;
            hash['e' - 'a']--;
            hash['r' - 'a']--;
            hash['o' - 'a']--;
        }

        while (hash['t' - 'a'] > 0 && hash['w' - 'a'] > 0 && hash['o' - 'a'] > 0)
        {
            digits[2]++;
            hash['t' - 'a']--;
            hash['w' - 'a']--;
            hash['o' - 'a']--;
        }

        while (hash['s' - 'a'] > 0 && hash['i' - 'a'] > 0 && hash['x' - 'a'] > 0)
        {
            digits[6]++;
            hash['s' - 'a']--;
            hash['i' - 'a']--;
            hash['x' - 'a']--;
        }

        while (hash['e' - 'a'] > 0 && hash['i' - 'a'] > 0 && hash['g' - 'a'] > 0 && hash['h' - 'a'] > 0 && hash['t' - 'a'] > 0)
        {
            digits[8]++;
            hash['e' - 'a']--;
            hash['i' - 'a']--;
            hash['g' - 'a']--;
            hash['h' - 'a']--;
            hash['t' - 'a']--;
        }

        string output = "";
        for (int i = 0; i < 10; i++)
        {
            while (digits[i])
            {
                output += (i + '0');
                digits[i]--;
            }
        }

        return output;
    }
};