/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
        Node* arraytoBST(vector<int>&arr, int low, int high){
            if(low> high) return NULL;
            int mid = low+(high-low)/2;
            Node* ans = new Node(arr[mid]);
            ans->left = arraytoBST(arr, low, mid-1);
            ans->right = arraytoBST(arr,mid+1,high);
            return ans;
        }
    Node* sortedArrayToBST(vector<int>& arr) {
        // code here
        return arraytoBST(arr,0,arr.size()-1);
    }
};