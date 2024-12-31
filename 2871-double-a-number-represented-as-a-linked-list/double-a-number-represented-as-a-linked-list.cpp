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
    ListNode* doubleIt(ListNode* head) {
        if(head->val>4){
            ListNode* ans=new ListNode(0);
            ans->next=head;
            head=ans;
        }
        ListNode* ans=head;

        while(ans){
            ans->val=(ans->val)*2%10;
            if(ans->next&&ans->next->val>4)ans->val=ans->val+1;
            ans=ans->next;
        }
        return head;

        
    }
};