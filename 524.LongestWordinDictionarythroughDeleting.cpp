class Solution
{
public:
    bool validWord(string &w, string &s)
    {

        int j = 0;
        for (int i = 0; i < s.size() && j < w.size(); i++)
        {
            if (s[i] == w[j])
            {
                j++;
            }
        }

        return j == w.size();
    }

    string findLongestWord(string s, vector<string> &d)
    {

        string out = "";

        for (string w : d)
        {
            if (w.size() > out.size() || (w.size() == out.size() && w < out))
            {
                if (validWord(w, s))
                {
                    out = w;
                }
            }
        }

        return out;
    }
};