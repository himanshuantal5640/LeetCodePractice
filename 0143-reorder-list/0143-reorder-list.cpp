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
        //step 1: find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        //step 2 : reverse second half
        ListNode* prev = NULL;
        ListNode* curr = slow->next;
        slow->next = NULL;
        while(curr != NULL){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        //step 3:  merge two halfs
        ListNode* f = head;
        ListNode* s = prev;
        while(s != NULL){
            ListNode* t1 = f->next;
            ListNode* t2 = s->next;
            f->next = s;
            s->next = t1;
            f = t1;
            s = t2;

        }
    }
};