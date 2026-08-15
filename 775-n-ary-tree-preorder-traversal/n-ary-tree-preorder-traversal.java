/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    // void helper(Node root,List<Integer> ans ){
    //     if(root==null) return;
    //     ans.add(root.val);
    //     for(Node x : root.children) {
    //         helper(x,ans);
    //     }
    // }
    public List<Integer> preorder(Node root) {
        List<Integer> ans = new ArrayList<>();
        if(root==null) return ans;
        //helper(root, ans);
        Stack<Node> st = new Stack<>();
        st.push(root);
        while(!st.empty()) {
            Node f = st.pop();
            ans.add(f.val);
            List<Node> children = f.children;
            for(int i=children.size()-1; i>=0; i--) {
                st.push(children.get(i));
            }
        }
        return ans;
    }
}