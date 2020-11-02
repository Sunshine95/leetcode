class Solution
{
public:
    vector<string> out;
    vector<vector<int>> digmap;

    void bktrk(int pos, string &word, string &digits)
    {

        if (pos == digits.size())
        {
            out.push_back(word);
            return;
        }

        for (int i = 0; i < digmap[digits[pos] - '0'].size(); i++)
        {

            char c = digmap[digits[pos] - '0'][i];

            word += c;
            bktrk(pos + 1, word, digits);
            word.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {

        if (digits.size() == 0)
        {
            return out;
        }

        string word = "";

        digmap.resize(10);
        digmap[2] = {'a', 'b', 'c'};
        digmap[3] = {'d', 'e', 'f'};
        digmap[4] = {'g', 'h', 'i'};
        digmap[5] = {'j', 'k', 'l'};
        digmap[6] = {'m', 'n', 'o'};
        digmap[7] = {'p', 'q', 'r', 's'};
        digmap[8] = {'t', 'u', 'v'};
        digmap[9] = {'w', 'x', 'y', 'z'};

        bktrk(0, word, digits);
        return out;
    }
};