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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr,*next=nullptr;
        ListNode* curr = head;

        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    ListNode* findkthNode(ListNode* temp,int k){
        k-=1; 
        while(temp!=NULL && k>0){
            temp=temp->next; 
            k--; 
        }
        return temp; 
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
         
        ListNode* temp = head; 
        ListNode* prevLast = NULL; 
    
        while(temp != NULL){
            ListNode* kThNode = findkthNode(temp, k); 

            // If the Kth node is NULL -> (not a complete group)
            if(kThNode == NULL){
                // If there was a previous group,->link the last node to the current node
                if(prevLast) prevLast -> next = temp;
                // Exit the loop
                break; 
            }
            
            // Store the next node after the Kth node
            ListNode* nextNode = kThNode -> next; 

            // Disconnect the Kth node to prepare for reversal
            kThNode -> next = NULL; 

            // Reverse the nodes from temp to the Kth node
            reverseList(temp); 
            
            // Adjust the head if the reversal starts from the head
            if(temp == head){
                head = kThNode;
            }else{
                // Link the last node of the previous
                // group to the reversed group
                prevLast -> next = kThNode; 
            }

            // Update the pointer to the
            // last node of the previous group
            prevLast = temp; 

            // Move to the next group
            temp = nextNode; 
        }
        return head; 
    }
};