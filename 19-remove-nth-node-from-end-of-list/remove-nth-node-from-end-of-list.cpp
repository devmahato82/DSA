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
        int size = 1;
        ListNode* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
            size++;
        }
        if(size == n) {
            head = head->next;
        }
        else{
            ListNode* t = head;
            int idx = size-n-1;
            for(int i=1; i<=idx; i++){
                t= t->next;
            }
            t->next = t->next->next;
        }
        return head;
    }
};