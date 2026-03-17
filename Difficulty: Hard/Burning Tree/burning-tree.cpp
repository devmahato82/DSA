/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void markParent(Node* root, unordered_map<Node*,Node*> &parent ){
        if(root== NULL) return;
        if(root->left != NULL) parent[root->left] = root;
        if(root->right != NULL) parent[root->right] = root;
        markParent(root->left, parent);
        markParent(root->right,parent);
    }
    void markTarget(Node* root,int target, Node* &start){
        if(root == NULL) return;
        if(root->data == target) {
            start = root;
            return;
        }
        markTarget(root->left,target,start);
        markTarget(root->right,target,start);
        
    }
    
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*,Node*> parent;
        markParent(root,parent);
        Node* start= NULL;
        markTarget(root,target,start);
        unordered_set<Node*>visited;
        queue<pair<Node*,int>> q;
        q.push({start,0});
        visited.insert(start);
        int maxcount =0;
        while(q.size()>0){
            Node* temp = q.front().first;
            int level = q.front().second;
            q.pop();
            maxcount = max(maxcount,level);
            if(temp->left != NULL && visited.find(temp->left) == visited.end()) {
                q.push({temp->left, level+1});
                visited.insert(temp->left);
            }
            if(temp->right != NULL && visited.find(temp->right) == visited.end()) {
                q.push({temp->right, level+1});
                visited.insert(temp->right);
            }
            if(parent.find(temp) != parent.end()){
                if(visited.find(parent[temp]) == visited.end()){
                    q.push({parent[temp], level+1});
                    visited.insert(parent[temp]);
                }
            }
        }
        return maxcount;
        
        
        
    }
};