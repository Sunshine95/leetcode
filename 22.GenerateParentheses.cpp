class Solution
{
private:
    void bT(int n, string temp, int open, int clos)
    {

        if (temp.size() == 2 * n)
        {
            set.push_back(temp);
            return;
        }

        if (open < n)
        {
            temp += "(";
            open++;
            bT(n, temp, open, clos);
            temp = temp.substr(0, temp.size() - 1);
            open--;
        }
        if (clos < open)
        {
            temp += ")";
            clos++;
            bT(n, temp, open, clos);
            temp = temp.substr(0, temp.size() - 1);
            clos--;
        }

        return;
    }

public:
    vector<string> set;
    vector<string> generateParenthesis(int n)
    {

        bT(n, "", 0, 0);
        return set;
    }
};