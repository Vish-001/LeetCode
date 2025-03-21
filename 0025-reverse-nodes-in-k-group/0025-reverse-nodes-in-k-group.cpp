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
    void reverse(ListNode*head)
    {
        if(head==nullptr || head->next==nullptr) return;

        ListNode*curr=head;
        ListNode*prev=nullptr;
        while(curr)
        {
            ListNode*nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }

    }

    ListNode*Kth(ListNode*temp,int k)
    {
        k-=1;
        while(temp!=nullptr && k>0)
        {
            k--;
            temp=temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head==nullptr || head->next==nullptr || k<=1) return head;

        ListNode*temp=head;
        ListNode*prev=nullptr;

        while(temp!=nullptr)
        {
            ListNode*Kt=Kth(temp,k);
            if(Kt==nullptr) break;
            ListNode*nxt=Kt->next;
            Kt->next=nullptr;
            reverse(temp);
            if(head==temp)
            {
                head=Kt;
            }
            if(prev!=nullptr)
            {
                prev->next=Kt;
            }
            temp->next=nxt;
            prev=temp;
            temp=nxt;
        }
        return head;
    }
};