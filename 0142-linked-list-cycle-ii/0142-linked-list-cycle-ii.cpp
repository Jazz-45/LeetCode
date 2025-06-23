/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // unordered_set<ListNode*> s;

        // ListNode* temp=head;
        // while(temp && temp->next){
        //     if(s.find(temp)!=s.end()) return temp;
        //     else s.insert(temp);
        //     temp=temp->next;
        // }

        // return NULL;

        ListNode* slow=head;
        ListNode* fast=head;

        bool isCyclic=false;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                isCyclic=true;
                break;
            }
        }

        if(isCyclic==false) return NULL;

        slow=head;

        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return fast;
    }
};