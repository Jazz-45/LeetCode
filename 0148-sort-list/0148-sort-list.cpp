class Solution {
public:
    ListNode* findMid(ListNode* head){
        if(head==NULL || head->next==NULL) return head;

        ListNode* fast=head;
        ListNode* slow=head;

        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* head1 , ListNode* head2){
        ListNode* newHead= new ListNode();
        ListNode* temp=newHead;

        while(head1 && head2){
            if(head1->val<=head2->val){
                temp->next=head1;
                temp=head1;
                head1=head1->next;
                
            }
            else{
                temp->next=head2;
                temp=head2;
                head2=head2->next;
                
            }
        }

        if(head1!=NULL) temp->next=head1;
        else temp->next=head2;

        return newHead->next;
    }

    ListNode* mergeSort(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* mid=findMid(head);
        ListNode* head1=head,*head2=mid->next;
        mid->next=NULL;

        head1=mergeSort(head);
        head2=mergeSort(head2);

        return merge(head1,head2);
    }

    ListNode* sortList(ListNode* head) {
        // Using Merge Sort
        if(head==NULL || head->next==NULL) return head;
        return mergeSort(head);
    }
};