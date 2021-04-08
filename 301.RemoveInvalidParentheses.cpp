//301. Remove Invalid Parentheses
class Solution
{
public:
    unordered_set<string> valid;
    void addValidExpr(string &s, int pos, int leftCount, int rightCount, int left, int right, string &expr)
    {

        if (pos >= s.size())
        {
            if (left == 0 && right == 0)
            {
                valid.insert(expr);
            }
        }
        else
        {

            char ch = s[pos];

            if (ch == '(' && left > 0)
            {
                addValidExpr(s, pos + 1, leftCount, rightCount, left - 1, right, expr);
            }
            else if (ch == ')' && right > 0)
            {
                addValidExpr(s, pos + 1, leftCount, rightCount, left, right - 1, expr);
            }

            expr.push_back(ch);

            if (ch != '(' && ch != ')')
            {
                addValidExpr(s, pos + 1, leftCount, rightCount, left, right, expr);
            }
            else if (ch == '(')
            {
                addValidExpr(s, pos + 1, leftCount + 1, rightCount, left, right, expr);
            }
            else if (rightCount < leftCount)
            {
                addValidExpr(s, pos + 1, leftCount, rightCount + 1, left, right, expr);
            }

            expr.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s)
    {

        int left = 0;
        int right = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                left++;
            }
            else if (s[i] == ')')
            {
                if (left == 0)
                {
                    right++;
                }
                else
                {
                    left--;
                }
            }
        }

        string expr = "";
        addValidExpr(s, 0, 0, 0, left, right, expr);

        vector<string> result;
        for (string t : valid)
        {
            result.push_back(t);
        }

        return result;
    }
};