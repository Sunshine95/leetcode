class Solution
{
public:
    vector<string> out;

    void dfs(string S, int i)
    {

        for (; i < S.size(); i++)
        {
            string temp = S;
            if (islower(S[i]))
            {
                temp[i] = toupper(temp[i]);
                dfs(temp, i + 1);
            }
            else if (isupper(S[i]))
            {
                temp[i] = tolower(temp[i]);
                dfs(temp, i + 1);
            }
        }

        out.push_back(S);
        return;
    }

    vector<string> letterCasePermutation(string S)
    {

        dfs(S, 0);
        return out;
    }
};