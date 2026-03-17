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
    void helper(ListNode* l1, ListNode* l2, ListNode* ans,int carry){
        if(l1==NULL && l2==NULL && carry ==0) return;
        int sum =carry;
        if(l1) sum += l1->val;
        if(l2) sum += l2->val;
        ListNode* temp = new ListNode(sum%10);
        ans->next = temp; 
        helper(l1 ? l1->next: NULL, l2 ? l2->next:NULL,temp, sum/10);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        helper(l1,l2,ans,0);
        return ans->next;
    }
};