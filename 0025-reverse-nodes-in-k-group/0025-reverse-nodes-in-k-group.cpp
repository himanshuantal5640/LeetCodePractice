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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;
        while(cnt < k){
            if(temp == NULL){
                return head;
            }
            cnt++;
            temp=temp->next;
        }
        ListNode* prev = reverseKGroup(temp,k);
        temp = head;
        cnt = 0;
        while(cnt < k){
            ListNode* nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
            cnt++;
        }
        return prev;
    }
};