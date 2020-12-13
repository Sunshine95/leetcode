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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *head = new ListNode();
        ListNode *temp = head;
        int carry = 0;

        while (l1 && l2)
        {

            temp->val = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;

            l1 = l1->next;
            l2 = l2->next;

            if ((l1 || l2) || carry)
            {
                temp->next = new ListNode();
                temp = temp->next;
            }
        }

        while (l1)
        {

            temp->val = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;

            l1 = l1->next;
            if (l1 || carry)
            {

                temp->next = new ListNode();
                temp = temp->next;
            }
        }

        while (l2)
        {

            temp->val = (l2->val + carry) % 10;
            carry = (l2->val + carry) / 10;

            l2 = l2->next;
            if (l2 || carry)
            {

                temp->next = new ListNode();
                temp = temp->next;
            }
        }

        if (carry)
            temp->val = carry;
        return head;
    }
};