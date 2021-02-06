class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {

        stack<int> st;
        int pushi = 0, popj = 0;

        while (pushi < pushed.size())
        {
            while (!st.empty() && st.top() == popped[popj])
            {
                st.pop();
                popj++;
            }

            st.push(pushed[pushi]);
            pushi++;
        }

        while (!st.empty() && st.top() == popped[popj])
        {
            st.pop();
            popj++;
        }

        return popj == popped.size();
    }
};