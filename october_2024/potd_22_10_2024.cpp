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

    queue<TreeNode*> q;
    vector<long long> level;

    long long height(TreeNode* root){
        if(root == NULL)
            return 0;
        return max(height(root->left), height(root->right)) + 1;
    }

    void bfs(TreeNode* root){
        if(root == NULL)
            return;
        q.push(root);

        while(!q.empty()){
            long long levelSize = q.size();
            long long levelSum = 0;

            for(long long i = 0; i < levelSize; i++){
                TreeNode* currentNode = q.front();
                q.pop();
                levelSum += currentNode->val;  // Add node's value to the level sum
                // Enqueue left child
                if (currentNode->left) 
                    q.push(currentNode->left);
                // Enqueue right child
                if (currentNode->right) 
                    q.push(currentNode->right);
            }
        level.push_back(levelSum);
        }
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(height(root) < k)
            return -1;
        
        bfs(root);

        sort(level.begin(), level.end());

        return level[level.size() - k];
    }
};