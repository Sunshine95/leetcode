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
    ListNode *sortList(ListNode *head)
    {

        vector<int> list;
        ListNode *iti = head;
        int i = 0;

        while (iti)
        {
            list.push_back(iti->val);
            iti = iti->next;
        }

        sort(list.begin(), list.end());

        iti = head;

        while (iti)
        {
            iti->val = list[i];
            iti = iti->next;
            i++;
        }

        return head;
    }
};