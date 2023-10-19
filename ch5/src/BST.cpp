#include <algorithm>
#include <queue>
#include <fstream>
#include "BST.h"

TreeNode* BST::backtrack_insert(TreeNode *root, TreeNode *new_node){
    if (root == nullptr) {
        return new_node;
    }
    if (new_node->data > root->data){
        root->right = backtrack_insert(root->right, new_node);
    }
    else{
        root->left = backtrack_insert(root->left, new_node);
    }
    return root;
}

void BST::insert(int data){
    TreeNode * new_node = new TreeNode(data);
    root = backtrack_insert(root, new_node);
}

void BST::level_traverse(){
    if (root == nullptr) {
        return;
    }

    std::queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()) {
        int size = que.size();
        while (size--){
            TreeNode * tmp = que.front();
            que.pop();
            std::cout << tmp->data << " ";
            if (tmp->left != nullptr) {
                que.push(tmp->left);
            }
            if(tmp->right != nullptr) {
                que.push(tmp->right);
            }
        }
        std::cout << std::endl;
    }

}