/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x->nex, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* temp, int x) {
        queue<ListNode*>q; 
  
        ListNode* ans=new ListNode(0);
        ListNode* res=ans;

        while(temp){
            if(temp->val<x){
                ans->next=temp;
                ans=ans->next;
            }
            else{
                q.push(temp);
            
            }
            temp=temp->next;
        }
       
        while(!q.empty()){
            ans->next=q.front();
            ans=ans->next;
            q.pop();
        }
        ans->next=NULL;
        return res->next;
    }
};