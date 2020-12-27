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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        int sz = n;
        int m = n;

        ListNode *last;
        ListNode *nthNode;
        ListNode *prev;

        last = head;

        while (--m)
        {
            last = last->next;
        }

        nthNode = head;
        int k = 1;

        while (last->next)
        {
            last = last->next;
            nthNode = nthNode->next;

            if (k)
            {
                prev = head;
                k = 0;
            }
            else
            {
                prev = prev->next;
            }

            sz++;
        }

        if (sz == n)
        {
            return head->next;
        }

        prev->next = nthNode->next;
        delete (nthNode);
        return head;
    }
};