
class Solution
{
public:
    ListNode* Rev(ListNode*&temp)
    {
        ListNode*curr=temp;
        ListNode*prev=nullptr;
        while(curr->next)
        {
            ListNode*nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        curr->next=prev;
        return curr;
    }

    bool isPalindrome(ListNode* head) 
    {
        if(head==nullptr || head->next==nullptr) return true;
        ListNode*slow=head;
        ListNode*fast=head;

        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow=Rev(slow);
        fast=head;
        while(fast->next)
        {
            if(fast->val!=slow->val) return false;
            fast=fast->next;
            slow=slow->next;
        }
        return true;
    }
};