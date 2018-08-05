//
// Created by ljl on 8/4/2018.
//

#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
};
class Solution {		//时间复杂度高，怎么改进？
public:
	int maxheight(TreeNode *root) {
		if (root == NULL) return 0;
		if (maxheight(root->left) == -1) return -1;
		if (maxheight(root->right) == -1) return -1;
		int leftH = maxheight(root->left) + 1;
		int rightH = maxheight(root->right) + 1;
		int balanceFactor = leftH - rightH;
		if (balanceFactor<2 && balanceFactor>-2) {
			return max(leftH, rightH);
		}

		return -1;
	}
	bool isBalanced(TreeNode *root) {
		int balanceFactor = maxheight(root);
		if (balanceFactor == -1) return false;
		else return true;
	}
};