class Solution {
public:
	int goodNodes(TreeNode* root, int maxval = -10000) {
		if (!root) return 0;
		int newmax = max(maxval, root->val);
		return (root->val >= maxval) + goodNodes(root->left, newmax) + goodNodes(root->right, newmax);
	}
};