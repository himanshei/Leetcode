/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void AssignParent(TreeNode*root,map<TreeNode*,TreeNode*>&parent){
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()>0){
            TreeNode*temp=q.front();
            q.pop();
            if(temp->left){
                q.push(temp->left);
                parent[temp->left]=temp;
            }
            if(temp->right){
                q.push(temp->right);
                parent[temp->right]=temp;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>parent;
        AssignParent(root,parent);
        map<TreeNode*,bool>vis;
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=1;
        while(q.size()>0){
            int d=q.size();
            for(int i=0;i<d;i++){
                TreeNode*node=q.front();
                q.pop();
                if(k==0){
                    ans.push_back(node->val);
                }
                if(node->left && vis[node->left]==0){
                    q.push(node->left);
                    vis[node->left]=1;
                }
                if(node->right && vis[node->right]==0){
                    q.push(node->right);
                    vis[node->right]=1;
                }
                if(parent.find(node)!=parent.end() && vis[parent[node]]==0){
                    q.push(parent[node]);
                    vis[parent[node]]=1;
                }
            }
            k--;
        }
        return ans;

    }
};