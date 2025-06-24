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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        if(k==0) return head;
        ListNode* tail=head;

        int length=1;
        while(tail->next!=NULL){
            tail=tail->next;
            length++;
        }

        k%=length;
        if(k==0) return head;
        int move=length-k-1;

        ListNode* newHead;
        ListNode* temp=head;
        while(move--){
            temp=temp->next;
        }
        newHead=temp->next;
        temp->next=NULL;
        tail->next=head;

        return newHead;
    }
};