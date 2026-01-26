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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || left == right){
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        for(int i=1;i<left;i++){
            prev = curr;
            curr = curr->next;
        }
        ListNode* leftPrev = prev;
        ListNode* subTail = curr;
        for(int i=0;i<= right-left;i++){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        if(leftPrev != NULL){
            leftPrev->next = prev;
        }
        else{
            head = prev;
        }
        subTail->next = curr;
        return head;
    }
};