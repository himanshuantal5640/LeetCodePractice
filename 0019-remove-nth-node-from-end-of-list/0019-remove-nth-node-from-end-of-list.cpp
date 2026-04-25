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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* temp = head;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        if(n == cnt){
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;
            return head;
        }
        temp = head;
        int i = 1;
        while(i < cnt - n){
            temp = temp->next;
            i++;
        }
        ListNode* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        return head;

    }
};