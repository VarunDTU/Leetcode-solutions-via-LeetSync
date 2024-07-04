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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans=new ListNode(-1),*node=ans;
        int sum=0;
        while(head){
            if(head->val==0){
                ListNode* temp=new ListNode(sum);
                ans->next=temp;
                ans=ans->next;
                sum=0;
            }
            else{
                sum+=head->val;
            }
            head=head->next;
        }
        return node->next->next;
    }   
};