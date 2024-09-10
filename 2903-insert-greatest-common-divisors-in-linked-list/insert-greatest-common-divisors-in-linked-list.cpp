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
    int gcd(int a, int b) {
        while (a > 0 && b > 0) {
            if (a > b)
                a = a % b;
            else
                b = b % a;
        }
        if (a == 0)
            return b;
        return a;
    }

public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head->next)
            return head;
        ListNode* ans = head;
        while (head && head->next) {
            ListNode* next = head->next;
            int gcdVal = gcd(head->val, next->val);
            ListNode* gcdNode = new ListNode(gcdVal);
            head->next = gcdNode;
            gcdNode->next = next;
            head = next;
        }
        return ans;
    }
};