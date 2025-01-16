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
    void reverse(ListNode*temp)
    {
        ListNode*prev=nullptr;
        while(temp!=nullptr)
        {
            ListNode*nxt=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nxt;
        }
    }

    ListNode*Kth(ListNode*temp,int k)
    {
        k-=1;
        while(k>0 && temp!=nullptr)
        {
            k--;
            temp=temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode*prev=nullptr;
        ListNode*temp=head;
        while(temp!=nullptr)
        {
            ListNode*Kt=Kth(temp,k);
            if(Kt==nullptr) break;
            ListNode*nxt=Kt->next;
            Kt->next=nullptr;
            reverse(temp);
            if(temp==head)
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