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
class Solution {
public:
    ListNode*Rev(ListNode*head)
    {
        if(head->next==nullptr) return head;

        ListNode*prev=nullptr;
        ListNode*curr=head;
        ListNode*nxt=nullptr;

        while(curr!=nullptr)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;

    }

    bool isPalindrome(ListNode* head) 
    {
        if(head==nullptr || head->next==nullptr) return true;

        ListNode*slow=head;
        ListNode*fast=head;

        while(fast->next!=nullptr && fast->next->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode*newH=Rev(slow->next);

        ListNode*dummy=head;

        while(newH!=nullptr)
        {
            if(newH->val!=dummy->val) return false;
            newH=newH->next;
            dummy=dummy->next;
        }
        
        return true;

    }
};