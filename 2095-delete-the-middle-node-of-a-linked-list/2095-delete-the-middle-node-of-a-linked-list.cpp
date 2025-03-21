class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) 
            return nullptr;  // If only one node, return nullptr

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr; // To track node before slow

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;   // Store previous node of slow
            slow = slow->next;
            fast = fast->next->next;
        }

        // Delete the middle node
        prev->next = slow->next;
        delete slow;

        return head;
    }
};
