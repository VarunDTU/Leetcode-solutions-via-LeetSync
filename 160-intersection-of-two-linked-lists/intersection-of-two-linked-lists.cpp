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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       ListNode* currA=headA,*currB=headB;
       while(currA!=currB){
        currA=currA?currA->next:headB;
        currB=currB?currB->next:headA;
       }
       return currA;
    }
};