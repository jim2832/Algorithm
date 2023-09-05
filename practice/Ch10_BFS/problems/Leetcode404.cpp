#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// BFS解法

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        //exception
        if(root == 0){
            return 0;
        }

        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto current = q.front();
            q.pop();
            // 左葉節點的特性
            // 1.在current的左子樹
            // 2.自己本身不為空
            // 3.其左右子點皆為空
            if(current->left != 0 && current->left->left == 0 && current->left->right == 0){
                sum += current->left->val;
            }
            if(current->left != 0){
                q.push(current->left);
            }
            if(current->right != 0){
                q.push(current->right);
            }
        }

        return sum;
    }
};