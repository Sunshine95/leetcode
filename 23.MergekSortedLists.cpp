//23. Merge k Sorted Lists
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        if (!lists.size())
            return NULL;

        vector<ListNode *> itis = lists;
        ListNode *mhead;
        ListNode *miti;
        miti = new ListNode(-42000, NULL);
        int nullCount = 0;

        mhead = miti;

        int mVal, mIdx;
        while (nullCount < lists.size())
        {

            mVal = 42000;
            nullCount = 0;

            for (int i = 0; i < lists.size(); i++)
            {

                if (itis[i] == NULL)
                {
                    nullCount++;
                    if (nullCount == lists.size())
                        break;
                    continue;
                }

                if (itis[i]->val < mVal)
                {
                    mVal = itis[i]->val;
                    mIdx = i;
                }
            }

            if (nullCount == lists.size())
                break;

            miti->next = itis[mIdx];
            itis[mIdx] = itis[mIdx]->next;
            miti = miti->next;
        }

        return mhead->next;
    }
};