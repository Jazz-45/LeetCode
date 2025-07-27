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

typedef pair<int,ListNode*> p;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();

        vector<p> arr;
        for(int i=0;i<n;i++) 
            if(lists[i]!=NULL) arr.push_back({lists[i]->val,lists[i]});

        priority_queue<p,vector<p>,greater<p>> pq(arr.begin(),arr.end());

        ListNode* newHead=new ListNode(-1);
        ListNode* temp=newHead;
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();

            ListNode* curr=new ListNode(x.first);
            temp->next=curr;
            temp=temp->next;
            
            if(x.second->next!=NULL) pq.push({x.second->next->val,x.second->next});
        }

        return newHead->next;


    }
};