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
    ListNode *partition(ListNode *head, int x)
    {
        if (!head || !head->next)
            return head;
        ListNode less(0), greater(0);
        ListNode *p1 = &less, *p2 = &greater;
        while (head)
        {
            // ref idea is copied from some top solution
            // It is a nice trick
            ListNode *&ref = (head->val < x ? p1 : p2);
            ref = ref->next = head;
            head = head->next;
        }
        p1->next = greater.next;
        p2->next = NULL;
        return less.next;
    }
};