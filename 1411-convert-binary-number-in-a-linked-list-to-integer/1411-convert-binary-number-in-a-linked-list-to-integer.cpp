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
        ListNode* newhead=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return newhead;
    }

    int getDecimalValue(ListNode* head) {
        int base=1;
        int value=0;

        ListNode* newhead=reverseList(head);

        while(newhead!=NULL){
            if(newhead->val==1) value+=base;
            base=base*2;
            newhead=newhead->next;
        }
        return value;
    }
};