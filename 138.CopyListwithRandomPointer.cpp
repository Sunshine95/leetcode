/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {

        if (head == NULL)
            return NULL;

        Node *headcopy = new Node(head->val);
        Node *itcopy = headcopy;
        Node *it = head;
        vector<Node *> pointers;

        int i = 0;
        while (it->next)
        {
            it->val = i;
            it = it->next;

            itcopy->next = new Node(it->val);
            pointers.push_back(itcopy);
            itcopy = itcopy->next;

            i++;
        }

        it->val = i;
        pointers.push_back(itcopy);
        it = head;
        itcopy = headcopy;

        while (it)
        {
            Node *t = it->random;
            if (t == NULL)
            {
                itcopy->random = NULL;
            }
            else
            {
                //cout << "flag ";
                itcopy->random = pointers[t->val];
            }

            it = it->next;
            itcopy = itcopy->next;
        }

        return headcopy;
    }
};