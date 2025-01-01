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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* next = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return next;
    }

public:
    int pairSum(ListNode* head) {
        ListNode* firstNode=head,*secondNode=head;
        while(secondNode&&secondNode->next){
            firstNode=firstNode->next;
            secondNode=secondNode->next->next;
        }
        secondNode=reverseList(firstNode);
        int ans=0;
        while(secondNode){
            ans=max(ans,secondNode->val+head->val);
            secondNode=secondNode->next;
            head=head->next;
        }
        return ans;
        return 0;
    }
};