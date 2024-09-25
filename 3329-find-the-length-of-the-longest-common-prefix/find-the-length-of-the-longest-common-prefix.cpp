
class Solution {
     class Node{
        public:
            Node* digits[10];   
    };
    void add(Node* head, string t){
        Node* ptr = head;
        for(auto c: t){
            if(!ptr->digits[c - '0']) ptr->digits[c - '0'] = new Node();
            ptr = ptr->digits[c-'0'];
        }
    }
    int check(Node *head,string word){
        int count=0;
        for(auto itr:word){
            if(head->digits[itr-'0'])count++;
            else break;
            head=head->digits[itr-'0'];
        }
        return count;
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        if(arr1.size()>arr2.size())return longestCommonPrefix(arr2,arr1);
        Node *head=new Node();
        for(auto itr:arr1)add(head,to_string(itr));
        int ans=0;
        for(auto itr:arr2)ans=max(ans,check(head,to_string(itr)));
        return ans;
    }
};