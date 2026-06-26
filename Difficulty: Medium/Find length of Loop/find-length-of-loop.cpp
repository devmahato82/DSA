/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int countLength(Node *target){
        Node *temp = target;
        int count = 1;
        while(temp->next != target){
            temp = temp->next;
            count++;
        }
        return count;
    }
    int lengthOfLoop(Node *head) {
        // code here
        Node* slow = head;
        Node* fast = head;
        while( fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                return countLength(slow);
            }
        }
        return 0;
    }
};