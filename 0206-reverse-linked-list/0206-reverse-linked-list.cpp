class Solution {
public:
    ListNode* helper(ListNode* curr,ListNode* prev,ListNode* next){
        if(curr==NULL) return prev;

        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        return helper(curr,prev,next);
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr,*next=nullptr;
        ListNode* curr = head;

        return helper(curr,prev,next);

        // while(curr!=NULL){
        //     next=curr->next;
        //     curr->next=prev;
        //     prev=curr;
        //     curr=next;
        // }
        // return prev;
    }
};