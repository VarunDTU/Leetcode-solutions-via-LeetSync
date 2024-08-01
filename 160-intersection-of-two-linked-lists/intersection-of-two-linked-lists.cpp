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
    ListNode* setNode(ListNode* A, int diff) {
        while(diff!=0){
            A=A->next;
            diff--;
        }
        return A;
    }
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int l1 = 0, l2 = 0;
        ListNode* temp=headA;
        while (headA) {
            l1++;
            headA = headA->next;
        }
        headA=temp;
        temp=headB;
        while (headB) {
            l2++;
            headB = headB->next;
        }
        headB=temp;
        if (l1 > l2)
            headA=setNode(headA, l1 - l2);
        else if (l1 < l2)
            headB=setNode(headB, l2 - l1);
        while (headA && headB) {
            cout<<headA->val<<headB->val<<endl;
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};