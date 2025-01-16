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
    Node* copyRandomList(Node* head) 
    {
        if (head == nullptr) return head;
        Node* temp = head;
        Node* newH = nullptr;

        // Step 1: Duplicate Nodes
        while (temp != nullptr) {
            Node* T = new Node(temp->val);
            if (newH == nullptr) newH = T;
            T->next = temp->next;
            temp->next = T;
            temp = temp->next->next;
        }

        // Step 2: Copy Random Pointers
        temp = head;
        Node* T = newH;
        while (temp != nullptr) {
            if (temp->random == nullptr) {
                T->random = nullptr;
            } else {
                T->random = temp->random->next;
            }
            temp = T->next;
            if (temp != nullptr) T = temp->next;
        }

        // Step 3: Separate Original and Duplicated Lists
        T = newH;
        temp = head;
        while (temp != nullptr) 
           {
            temp->next = T->next;
            if (temp->next != nullptr) T->next = temp->next->next;
            temp = temp->next;
            if (temp != nullptr) T = temp->next;
        }

        return newH;
    }
};
