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
    ListNode* reverseList(ListNode* head){
        if(head==NULL || head->next==NULL) return head;

        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* next;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head->next==NULL) return true;

        ListNode* fast=head;
        ListNode* slow=head;

        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* head2=reverseList(slow->next);
        slow->next=NULL;

        ListNode* head1=head;

        while(head2){
            if(head1->val != head2->val) return false;
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
};