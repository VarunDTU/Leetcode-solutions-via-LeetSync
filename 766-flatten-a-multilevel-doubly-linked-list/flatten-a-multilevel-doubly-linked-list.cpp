/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {

public:
    Node* flatten(Node* head) {
        Node* ans = head;
        while (head) {
            if (head->child) {

                Node* temp = head->next;
                head->next = head->child;
                head->next->prev = head;
                head->child = NULL;
                Node* next = head->next;
                while (next->next)
                    next = next->next;
                if (temp) {
                    next->next = temp;
                    temp->prev = next;
                }
            }
            head = head->next;
        }
        return ans;
    }
};