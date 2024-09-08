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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = 0;
        ListNode* temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }
        vector<ListNode*> ans(k,NULL);
        int times = length / k, bigger = length % k;
        ListNode* prev;
        temp = head;
        for (int j = 0; j < k&&temp; j++) {
            int parts = times +( bigger > 0 ? 1 : 0);
           
            bigger--;
            ans[j]=temp;
            for (int i = 0; i < parts; i++) {
                prev=temp;
                temp = temp->next;
            }
                prev->next=nullptr;
        }
        return ans;
    }
};