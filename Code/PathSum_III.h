#pragma once

#define PATH_SUM_III

#include <unordered_map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

int pathSum(TreeNode* root, int sum)
{
	if (root == nullptr) return 0;
	int ans = 0;
	unordered_map<int, int> mp;
	mp[0] = 1;

	DFS_alg(root, sum, 0, ans, mp);

	return ans;
}

void DFS_alg(TreeNode* node, int &targetSum, int currentSum,
	int &ans, unordered_map<int, int> &mp)
{

	currentSum = currentSum + node->val;
	int seen = currentSum - targetSum;
	if (mp.count(seen))
		ans += mp[seen];

	mp[currentSum]++;
	if (node->left)
		DFS_alg(node->left, targetSum, currentSum, ans, mp);
	if (node->right)
		DFS_alg(node->right, targetSum, currentSum, ans, mp);
	mp[currentSum]--;

	return;
}
