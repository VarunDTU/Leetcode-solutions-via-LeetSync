/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    
public:
    Node* cloneGraph(Node* node) {
        if(!node)return NULL;
        unordered_map<int,Node*>mp;
        queue<Node*>q;
        Node* Nnode=new Node(node->val,{});
        mp[node->val]=Nnode;
        q.push(node);
        while(!q.empty()){
            Node* oldN=q.front();
            q.pop();
            for(Node* itr:oldN->neighbors){
                if(mp.find(itr->val)==mp.end()){
                    q.push(itr);
                    Node* temp=new Node(itr->val);
                    mp[oldN->val]->neighbors.push_back(temp);
                    mp[temp->val]=temp;
                }
                else{
                    Node* temp=mp[itr->val];
                    mp[oldN->val]->neighbors.push_back(temp);
                }
            }
        }
        return Nnode;
    }
};