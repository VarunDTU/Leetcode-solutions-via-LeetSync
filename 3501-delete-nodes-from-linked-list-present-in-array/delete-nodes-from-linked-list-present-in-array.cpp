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
    void deleteNode(ListNode* head){
        head->next=head->next->next;
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>dic;
        for(auto itr:nums)dic.insert(itr);
        ListNode * temp=head;
        while(head&&head->next){
            //cout<<head->val;
            if(dic.find(head->next->val)!=dic.end())deleteNode(head);
            else head=head->next;
        }
        if(dic.find(temp->val)!=dic.end()&&temp) temp=temp->next;
        return temp;

    }
};