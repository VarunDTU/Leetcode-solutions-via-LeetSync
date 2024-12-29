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
    ListNode* deleteDuplicates(ListNode* head) {
     ListNode* ans=head;
     ListNode* temp=head;
     while(temp){
        while(temp&&ans->val==temp->val){
            temp=temp->next;
        }
        ans->next=temp;
        ans=ans->next;
        if(!ans)break;
        temp=ans->next;
     }  

     return head; 
    }
};