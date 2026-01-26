/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return head;
        }
        unordered_map<Node*,Node*> mpp;//for random pointer store addres of old and new node
        Node* newHead = new Node(head->val);
        Node* oldTemp = head->next;//head->next bcz we already created copy of head
        Node* newTemp = newHead;
        mpp[head] = newHead;
        //step 1 is copy LL
        while(oldTemp != NULL){
            Node* copyNode = new Node(oldTemp->val);
            mpp[oldTemp] = copyNode;
            newTemp->next = copyNode;
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }
        //traverse again for random pointer
        oldTemp = head;
        newTemp = newHead;
        while(oldTemp != NULL){
            newTemp->random = mpp[oldTemp->random];
            newTemp = newTemp->next;
            oldTemp = oldTemp->next;
        }
        return newHead;
    }
};