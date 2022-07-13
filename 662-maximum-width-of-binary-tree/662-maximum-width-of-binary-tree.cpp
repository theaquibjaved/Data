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
        int widthOfBinaryTree(TreeNode * root) {
  if (!root)
    return 0;
  int ans = 0;
  queue < pair < TreeNode * , int >> q;
  q.push({root,0});
  while (!q.empty()) {
    int size = q.size();
    int curMin = q.front().second;
    int leftMost, rightMost;
    for (int i = 0; i < size; i++) {
      int cur_id = q.front().second - curMin; // subtracted to prevent integer overflow
      TreeNode * temp = q.front().first;
      q.pop();
      if (i == 0) leftMost = cur_id;
      if (i == size - 1) rightMost = cur_id;
      if (temp -> left)
        q.push({temp -> left,cur_id * 2LL + 1});
      if (temp -> right)
        q.push({temp -> right,cur_id * 2LL + 2});
    }
    ans = max(ans, rightMost - leftMost + 1);
  }
  return ans;
}
    
    
//     int widthOfBinaryTree(TreeNode* root) {
//         if(!root)
//             return 0;
        
//         int ans = 0;
//         queue<pair<TreeNode*, int>> q;
//         q.push({root, 0});
        
//         while(!q.empty()){
//             int size = q.size();
//             int mini = q.front().second;
//             int first, last;
            
//             for(int i = 0; i < size; i++){
//                 int curr = q.front().second - mini;
//                 TreeNode* node = q.front().first;
//                 q.pop();
                
//                 if(i == 0) first = curr;
//                 if(i == size-1) last = curr;
                
//                 if(node->left)
//                     q.push({node->left, curr*2+1});
//                 if(node->right)
//                     q.push({node->right, curr*2+2});
//             }
//             ans = max(ans, last-first+1);
//         }
//         return ans;
//     }
};