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
    void reorderList(ListNode* head) {
        vector<ListNode* >v;
        ListNode* temp=head;
        while(temp){
            v.push_back(temp);
            temp=temp->next;
        }
        int s=0,e=v.size()-1;
        temp=new ListNode(0);
        while(s<=e){
           temp->next=v[s];
           v[s]->next=v[e];
           temp=v[e];
           temp->next=NULL;
           e--;
           s++;
        }

    }
};