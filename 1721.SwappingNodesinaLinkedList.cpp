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
    ListNode *swapNodes(ListNode *head, int k)
    {

        ListNode *a;
        ListNode *b;
        ListNode *temp;

        a = b = temp = head;

        while (--k)
        {
            a = a->next;
            temp = temp->next;
        }

        temp = temp->next;
        while (temp != NULL)
        {
            temp = temp->next;
            b = b->next;
        }

        int c = b->val;
        b->val = a->val;
        a->val = c;

        return head;
    }
};