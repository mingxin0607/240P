#include <iostream>
#include <queue>
#include "BST.h"


class BSTToHeapTransformer {
private:
    TreeNode* root;
    // convert a BST to a sorted array
    void inorderTraversal(TreeNode* node, std::vector<int>& arr);

    // if the array is ascending, build a minheap in form of a tree
    // if the array is descending, build a maxheap in form of a tree
    TreeNode* buildHeapFromSortedArray(const std::vector<int>& arr, int index);

public:
    BSTToHeapTransformer(TreeNode* bstRoot) : root(bstRoot) {}
    // convert BST to minheap
    TreeNode* convertToMinHeap();
    // convert BST to maxheap
    TreeNode* convertToMaxHeap();
    // print tree by passing root node
    void printTree(TreeNode* node);
};

