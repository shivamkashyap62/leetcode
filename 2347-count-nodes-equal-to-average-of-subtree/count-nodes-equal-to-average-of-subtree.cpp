/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=0;
    pair<int,int> postorder(TreeNode* root){
        if(root==NULL) return {0,0};
        pair<int,int> l =postorder(root->left);
        pair<int,int> r=postorder(root->right);

        int sum=l.first + r.first + root->val;
        int count=l.second + r.second +1;
        
        if(sum/count==root->val) ans++;
        return {sum,count};
        
    }
    int averageOfSubtree(TreeNode* root) {
        postorder(root);
        return ans;
    }
};