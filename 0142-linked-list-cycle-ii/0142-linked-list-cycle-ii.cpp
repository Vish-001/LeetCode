class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* a = nullptr;
        unordered_set<ListNode*> st;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            auto iter = st.find(fast);
            if (iter == st.end()) {
                st.insert(fast);
            } else {
                a = fast;
                break;
            }
            fast = fast->next;
        }

        return a;
    }
};
