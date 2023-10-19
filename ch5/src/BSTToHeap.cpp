#include "BSTToHeap.h"
#include <algorithm>

void BSTToHeapTransformer::inorderTraversal(TreeNode* node, std::vector<int>& values) {
    if (node) {
        inorderTraversal(node->left, values);
        values.push_back(node->data);
        inorderTraversal(node->right, values);
    }
}


TreeNode* BSTToHeapTransformer::buildHeapFromSortedArray(const std::vector<int>& arr, int index) {
    if (index >= arr.size()) {
        return nullptr;
    }

    int value = arr[index];
    TreeNode* node = new TreeNode(value);

    node->left = buildHeapFromSortedArray(arr, index*2+1);
    node->right = buildHeapFromSortedArray(arr, index*2+2);

    return node;
}

TreeNode* BSTToHeapTransformer::convertToMinHeap() {
    std::vector<int> arr;
    inorderTraversal(root, arr);

    int index = 0;
    return buildHeapFromSortedArray(arr, index);
}

TreeNode* BSTToHeapTransformer::convertToMaxHeap() {
    std::vector<int> arr;
    inorderTraversal(root, arr);
    std::reverse(arr.begin(), arr.end());
    // for (auto x : arr){
    //     std::cout << x << " ";
    // }
    // std::cout << std::endl;
    int index = 0;
    return buildHeapFromSortedArray(arr, index);
}

void BSTToHeapTransformer::printTree(TreeNode* node) {
    if (node == nullptr){
        return;
    }
    std::queue<TreeNode*> que;
    que.push(node);
    while(que.size()) {
        int sz = que.size();
        // std::cout << "size: " << sz << std::endl;
        while(sz--){
            TreeNode * tmp = que.front();
            que.pop();
            std::cout << tmp->data << " ";
            if (tmp->left) {
                que.push(tmp->left);
            }
            if(tmp->right) {
                que.push(tmp->right);
            }

        }
        std::cout << std::endl;
    }
}